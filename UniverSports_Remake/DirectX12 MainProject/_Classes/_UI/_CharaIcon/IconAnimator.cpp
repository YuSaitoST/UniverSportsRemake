#include "IconAnimator.h"
#include "DontDestroyOnLoad.h"
#include "_Classes/_FileNames/FileNames.h"
#include "_Classes/_ConstStrages/UIPosition.h"
#include "_Classes/_UI/_Fade/Fade.h"

bool IconAnimator::display_(false);

IconAnimator::IconAnimator() : alpha_(0) {
	for (int _i = 0; _i <= 2; _i += 2) {
		icon_[_i]		= std::make_unique<CharaIcon>();
		icon_[_i + 1]	= std::make_unique<CharaIcon>();
	}

	display_time_ = std::make_unique<CountTimer>(3);
}

void IconAnimator::LoadAssets() {
	for (int _i = 0; _i <= 2; _i += 2) {
		icon_[_i]->LoadAssets(USFN_SP::LEFT_ICON[DontDestroy->ChoseColor_[_i]]);
		icon_[_i + 1]->LoadAssets(USFN_SP::LEFT_ICON[DontDestroy->ChoseColor_[_i + 1]]);
	}
}

void IconAnimator::Update(const float deltaTime) {
	if (display_) {
		display_time_->Update(deltaTime);
		display_ = !display_time_->TimeOut();
	}
	else
		display_time_->Reset();

	(display_) ?
		FADE::In(alpha_, FADE::COLORMAX, deltaTime * SPEED_FADEIN) :
		FADE::Out(alpha_, 0.0f, deltaTime * SPEED_FADEOUT);
}

void IconAnimator::Render(const int lifeCount, int index) {
	icon_[index]->Render(lifeCount, alpha_, US2D::Pos::Get().MainParam().LIFEICON_LPOS[index]);
}