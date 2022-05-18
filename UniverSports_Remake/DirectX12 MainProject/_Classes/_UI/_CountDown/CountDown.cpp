#include "CountDown.h"
#include "_Classes/_FileNames/FileNames.h"
#include "_Classes/_UI/_Fade/Fade.h"

CountDownUI::CountDownUI() : alpha_(0.0f), scale_(0.0f), se_played_(false) {
	se_count_		= new SoundPlayer();
}

CountDownUI::~CountDownUI() {
	delete se_count_;
}

void CountDownUI::Initialize() {
	se_count_->Initialize(L"_Sounds\\_SE\\_Main\\se_gameStart.wav", SOUND_TYPE::SE, 0.0f);
	alpha_			= 255.0f;
	scale_			= 1.0f;
}

void CountDownUI::LoadAssets() {
	for (int _i = 0; _i <= 2; _i += 2) {
		sprite_[_i] = DX9::Sprite::CreateFromFile(DXTK->Device9, USFN_SP::COUNTDOWN[_i].c_str());
		sprite_[_i + 1] = DX9::Sprite::CreateFromFile(DXTK->Device9, USFN_SP::COUNTDOWN[_i + 1].c_str());
	}
}

void CountDownUI::Update(const float deltaTime, float nowCount) {
	if (!se_played_) {
		SE_Play();
		se_played_ = true;
	}

	FADE::Out(alpha_, 0.0f, deltaTime * 255);
	alpha_ = (nowCount	<= 0.2f		) ? 0.0f : (alpha_ == 0.0f) ? 255.0f : alpha_;
	scale_ = (alpha_	== 255.0f	) ? 1.0f : (scale_ + 1.25f * deltaTime);
}

void CountDownUI::Render(float count) const {
	if (4 <= count)
		return;

	const int _count = std::min(std::max(0, (int)(count - 0.2f)), 3);

	DX9::SpriteBatch->Draw(
		sprite_[_count].Get(),
		SimpleMath::Vector3(POS_X, POS_Y, 0.0f),
		nullptr,
		DX9::Colors::RGBA(255, 255, 255, alpha_),
		SimpleMath::Vector3(0.0f, 0.0f, 0.0f),
		SimpleMath::Vector3(88.0f, 37.5f, 0.0f),
		SimpleMath::Vector2::One * scale_
	);
	DX9::SpriteBatch->ResetTransform();
}

void CountDownUI::SE_Play() {
	se_count_->PlayOneShot();
}