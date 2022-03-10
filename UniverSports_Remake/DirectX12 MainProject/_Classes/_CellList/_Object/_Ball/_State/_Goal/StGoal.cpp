#include "StGoal.h"
#include "_Classes/_CellList/_Object/_Ball/ObjBall.h"

void StGoal::Initialize() {
	
}

void StGoal::Update(ObjBall* ball) {

	if (ball->IsFieldOut(position_, 0.0f)) {
		//forward_ = SimpleMath::Vector3::Zero;
		//ball->SetForward(forward_);
		////ball->SetOwnerID(-1);

		//ball->SetBtPosition(SimpleMath::Vector3(99.0f, 99.0f, 0.0f));

		//// ゴールしたボールをループさせるなら
		////ball->SetIsGoal(false);
		////ball->SwitchState(ball->STATE::FLOAT);
	}
	else {
		// 移動処理
		position_ += forward_ * GAME_CONST.BA_SPEED_SHOT * 0.01f;
		//ball->SetBtPosition(position_);
	}
}