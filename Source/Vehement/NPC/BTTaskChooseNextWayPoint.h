// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskChooseNextWayPoint.generated.h"

/**
 * 
 */

UCLASS()
class VEHEMENT_API UBTTaskChooseNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskChooseNextWayPoint();

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WayPoint;

private:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	class UPatrolPoints* PatrolRoute;
};
