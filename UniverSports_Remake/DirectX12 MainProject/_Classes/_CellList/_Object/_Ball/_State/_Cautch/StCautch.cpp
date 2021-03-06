#include "StCautch.h"
#include "_Classes/_CellList/ObjectManager.h"
#include "_Classes/_CellList/_Object/_Ball/ObjBall.h"
#include "_Classes/_CellList/_Object/_Ball/_State/_Shot/StShot.h"
#include "_Classes/_CellList/_Object/_Ball/_State/_Float/StFloat.h"
#include "_Classes/_CellList/_PlayersInstructor/PlayersInstructor.h"
#include "DontDestroyOnLoad.h"

void StCautch::Initialize() {
	myState_ = B_STATE::CAUTCH;
}

void StCautch::Update(ObjBall* ball) {
	//状態変化
	if (!ball->IsInPlayerHands()) {
		//投げられたら
		std::unique_ptr<StShot> shot = std::make_unique<StShot>();
		ball->SwitchState(shot.release());
		return;
	}
	else if (ball->IsBreaked()) {
		//持ち主がやられたら
		ball->FlagResets();
		ball->SetOwnerID(-1);
		std::unique_ptr<StFloat> flo = std::make_unique<StFloat>();
		ball->SwitchState(std::move(flo).get());
		ball->SwitchColor(ObjBall::COLOR_TYPE::DEFAULT_COLOR);
		return;
	}

	//追尾
	ball->Following(BALL_PARAM.Z_AT_CAUTCH);
}