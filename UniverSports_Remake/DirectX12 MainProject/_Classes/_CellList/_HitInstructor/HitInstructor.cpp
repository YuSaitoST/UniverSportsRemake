#include "HitInstructor.h"
#include "_Classes/_CellList/ObjectManager.h"

void HitInstructor::BallCautch(const int playerID, const int ballID) {
	ObjectManager::GetBallObj(ballID)->WasCaught(playerID);
}

void HitInstructor::BallShot(const int ballID, DirectX::SimpleMath::Vector2 forward) {
	ObjectManager::GetBallObj(ballID)->WasThrown(forward);
}

void HitInstructor::BallBreak(const int ballID) {
	ObjectManager::GetBallObj(ballID)->WasGuessed();
}