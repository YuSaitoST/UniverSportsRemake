#include "SelectArrows.h"

SelectArrows::SelectArrows() {
	input_			= AL_NONE;

	sp_right_		= DX9::SPRITE{};
	sp_left_		= DX9::SPRITE{};

	pos_right_x_	= 0.0f;
	pos_left_x_		= 0.0f;
	pos_y_			= 0.0f;

	scale_right_	= 0.0f;
	scale_left_		= 0.0f;

	isFinBigger		= false;
	isFinSmaller	= false;
}

void SelectArrows::Initialize(float x_right, float x_left, float y) {
	pos_right_x_	= x_right	+ RECT;
	pos_left_x_		= x_left	+ RECT;
	pos_y_			= y			+ RECT;

	scale_right_	= 1.0f;
	scale_left_		= 1.0f;

	isFinSmaller	= true;
}

void SelectArrows::LoadAssets() {
	sp_right_		= DX9::Sprite::CreateFromFile(DXTK->Device9, L"_Images\\_Lobby\\arrow_right.png");
	sp_left_		= DX9::Sprite::CreateFromFile(DXTK->Device9, L"_Images\\_Lobby\\arrow_left.png");
}

void SelectArrows::LoadAssets(DX9::SPRITE right, DX9::SPRITE left) {
	sp_right_		= right;
	sp_left_		= left;
}

void SelectArrows::Update() {
	if (input_ == AL_NONE)
		return;

	(input_ == AL_RIGHT) ?
		Animation(scale_right_) :
		Animation(scale_left_);

	(input_ == AL_RIGHT) ?
		GetSmaller(scale_left_) :
		GetSmaller(scale_right_);
}

void SelectArrows::Render(float alpha) {
	DX9::SpriteBatch->Draw(
		sp_right_.Get(),
		SimpleMath::Vector3(pos_right_x_, pos_y_, -30.0f),
		nullptr,
		DX9::Colors::RGBA(255, 255, 255, alpha),
		SimpleMath::Vector3(0.0f, 0.0f, 0.0f),
		SimpleMath::Vector3(RECT, RECT, 0.0f),
		SimpleMath::Vector2::One * scale_right_
	);
	
	DX9::SpriteBatch->Draw(
		sp_left_.Get(),
		SimpleMath::Vector3(pos_left_x_, pos_y_, -30.0f),
		nullptr,
		DX9::Colors::RGBA(255, 255, 255, alpha),
		SimpleMath::Vector3(0.0f, 0.0f, 0.0f),
		SimpleMath::Vector3(12.5f, 12.5f, 0.0f),
		SimpleMath::Vector2::One * scale_left_
	);

	DX9::SpriteBatch->ResetTransform();
}

void SelectArrows::SetAnimation(INPUT_SELECT direct) {
	input_ = direct;
}

void SelectArrows::Animation(float& scale) {
	
	isFinBigger		= isFinSmaller	? (scale == SCALE_MAX)	: true;
	isFinSmaller	= isFinBigger	? (scale == 1.0f)		: true;

	if (!isFinBigger && isFinSmaller)
		GetBigger(scale);
	
	if ((isFinBigger && !isFinSmaller))
		GetSmaller(scale);

	input_			= (isFinBigger && isFinSmaller) ? AL_NONE : input_;
}

void SelectArrows::GetBigger(float& scale) {
	scale = std::min(scale + 0.15f, SCALE_MAX);
}

void SelectArrows::GetSmaller(float& scale) {
	scale = std::max(1.0f, scale - 0.1f);
}