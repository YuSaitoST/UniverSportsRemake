#include "CountDown.h"
#include "_Classes/_FileNames/FileNames.h"
#include "_Classes/_ConstStrages/US2DLayer.h"
#include "_Classes/_UI/_Fade/Fade.h"

CountDownUI::CountDownUI() : alpha_(0.0f), scale_(0.0f), soundPlay_(false) {
	se_count_ = std::make_unique<SoundPlayer>();
}

void CountDownUI::Initialize() {
	se_count_->Initialize(USFN_SOUND::SE::STARTCOUNT, SOUND_TYPE::SE, 0.0f);
	alpha_ = FADE::COLORMAX;
	scale_ = 1.0f;
}

void CountDownUI::LoadAssets() {
	for (int _i = 0; _i <= 2; _i += 2) {
		sprite_[_i] = DX9::Sprite::CreateFromFile(DXTK->Device9, USFN_SP::COUNTDOWN[_i].c_str());
		sprite_[_i + 1] = DX9::Sprite::CreateFromFile(DXTK->Device9, USFN_SP::COUNTDOWN[_i + 1].c_str());
	}
}

void CountDownUI::Update(const float deltaTime, float nowCount) {
	if (!soundPlay_) {
		se_count_->PlayOneShot();
		soundPlay_ = true;
	}

	FADE::Out(alpha_, 0.0f, deltaTime * FADE::COLORMAX);
	alpha_ = (nowCount	<= 0.2f				) ? 0.0f : (alpha_ == 0.0f				) ? FADE::COLORMAX : alpha_;
	scale_ = (alpha_	== FADE::COLORMAX	) ? 1.0f : (scale_ + 1.25f * deltaTime	);
}

void CountDownUI::Render(float count) const {
	if (4 <= count)
		return;

	const int _count = std::min(std::max(0, (int)(count - 0.2f)), 3);

	DX9::SpriteBatch->Draw(
		sprite_[_count].Get(),
		DirectX::XMFLOAT3(POS_X, POS_Y, (int)US2D::Layer::MAIN::UI_COUNTDOWN),
		nullptr,
		DX9::Colors::RGBA(FADE::COLORMAX, FADE::COLORMAX, FADE::COLORMAX, alpha_),
		DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f),
		DirectX::XMFLOAT3(CENTER_X, CENTER_Y, 0.0f),
		DirectX::SimpleMath::Vector2::One * scale_
	);
	DX9::SpriteBatch->ResetTransform();
}