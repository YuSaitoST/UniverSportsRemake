#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"
#include "_Classes/_InputClasses/InputChecker.h"

using namespace DirectX;

enum INPUT_SELECT {
	AL_RIGHT,
	AL_LEFT,
	AL_NONE
};

class SelectArrows {
public:
	SelectArrows();
	virtual ~SelectArrows() {};

	void Initialize(float x_right, float x_left, float y);
	void LoadAssets();
	void LoadAssets(DX9::SPRITE right, DX9::SPRITE left);
	void Update();
	void Render(float alpha);

	void SetAnimation(INPUT_SELECT direct);
	INPUT_SELECT NowState() const { return input_; };

private:
	void Animation(float& scale);
	void GetBigger(float& scale);
	void GetSmaller(float& scale);

private:
	const float RECT		= 12.5f;
	const float SCALE_MAX	= 1.5f;

private:
	INPUT_SELECT input_;

	DX9::SPRITE sp_right_;
	DX9::SPRITE sp_left_;

	float pos_right_x_;
	float pos_left_x_;
	float pos_y_;

	float scale_right_;
	float scale_left_;

	bool isFinBigger;
	bool isFinSmaller;
};