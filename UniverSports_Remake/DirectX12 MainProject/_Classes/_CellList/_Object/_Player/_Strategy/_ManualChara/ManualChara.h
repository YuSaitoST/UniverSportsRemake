#pragma once

#include "_Classes/_InputClasses/InputChecker.h"
#include "_Classes/_CellList/_Object/_Player/_Strategy/CharaStrategy.h"

class ManualChara final : public CharaStrategy {
public:
	ManualChara() {};
	virtual ~ManualChara() {};

	virtual void Initialize(int id, ObjPlayer* player);
	virtual void LoadAssets();
	virtual void Update(const float deltaTime);

	virtual void SeekRotateX(const float deltaTime, int index);
};