#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

class BallsInstructor {
public:
	BallsInstructor() {}
	virtual ~BallsInstructor() {}

	static void BallCautch(const int playerID, const int ballID);
	static void BallShot(const int ballID, DirectX::SimpleMath::Vector2 forward);
	static void BallBreakOfThrower(const int ballID);
	static void BallBreakOfTheHitter(const int ballID);
};