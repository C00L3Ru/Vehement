// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskChooseNextWayPoint.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <AIController.h>
#include "PatrolPoints.h"




UBTTaskChooseNextWayPoint::UBTTaskChooseNextWayPoint()
{

}

EBTNodeResult::Type UBTTaskChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get Patrol Points
	PatrolRoute = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolPoints>();
	
	// Check if we have a PatrolPoints component and if we have patrol Points in our array
	if(!ensure (PatrolRoute))
	
	
	if (PatrolRoute->GetPatrolPoints().Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No PatrolPoints in Patrol Route"));
		return EBTNodeResult::Failed;
	}
	
	// Set next Way point
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto IndexNo = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WayPoint.SelectedKeyName, PatrolRoute->GetPatrolPoints()[IndexNo]);
	
	// Cycle index number
	int32 NextWayPoint = (IndexNo +1 ) % PatrolRoute->GetPatrolPoints().Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextWayPoint);
	
	return EBTNodeResult::Succeeded;
}
