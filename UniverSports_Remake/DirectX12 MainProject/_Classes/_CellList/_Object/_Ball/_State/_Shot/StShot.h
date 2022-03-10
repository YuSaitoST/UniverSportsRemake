#pragma once

#include "_Classes/_CellList/_Object/_Ball/_State/BallState.h"

class StShot : public BallState {
public:
	StShot() = default;
	virtual ~StShot() = default;

	virtual void Initialize();
	virtual void Update(ObjBall* ball);
};