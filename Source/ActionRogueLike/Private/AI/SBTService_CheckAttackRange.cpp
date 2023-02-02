// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTService_CheckAttackRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"



void USBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
  
    //check distance betweeen ai pawn and target actor

    UBlackboardComponent* BlanckBoardComp = OwnerComp.GetBlackboardComponent();
    if (ensure(BlanckBoardComp))
    {
        AActor* TargetActor = Cast<AActor>(BlanckBoardComp->GetValueAsObject("TargetActor"));
        if (ensure(TargetActor))
        {
            AAIController* MyController = OwnerComp.GetAIOwner();
            if (ensure(MyController))
            {
                APawn* AIPawn = MyController ->GetPawn();
                if (ensure(AIPawn))
                {
                    float DistanceTo = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());

                    bool bWithinRange = DistanceTo < 2000.0f;

                    BlanckBoardComp ->SetValueAsBool(AttackRangeKey.SelectedKeyName, bWithinRange);

                }
            }
        }

    }

}
