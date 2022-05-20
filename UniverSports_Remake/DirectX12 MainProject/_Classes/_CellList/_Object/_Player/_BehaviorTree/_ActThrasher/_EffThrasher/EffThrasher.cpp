#include "EffThrasher.h"

EffThrasher::EffThrasher() : EffectBase(MOVE_TIME) {  // この時間が片道の再生時間
	timer_roop_		= new CountTimer(0.2f);  // 加速時の座標更新時間
	usedThrasher_	= false;
}

void EffThrasher::Update(const float deltaTime, float rotate_x, Vector3 position, Vector3 direction, float proportion) {
	Set_Position(position);

	TimerCount(deltaTime);
	Play();

	// 座標の更新
	if (isOver()) {
		ResetTime();
		Set_Position(position);
	}
	
	// 強出力
	if (usedThrasher_) {
		timer_roop_->Update(deltaTime);
		if (timer_roop_->TimeOut()) {
			timer_roop_->Reset();
			Set_Position(position);
		}
		Move(-direction * GAME_CONST.JT_MOVEMENT_NOMAL);
	}
	else
		Move(-direction * GAME_CONST.JT_MOVEMENT_ACCEL);

	const bool _isUsedJet = usedThrasher_ && (0.3 < proportion);
	Set_Rotate(Vector3(0.0f, 35.0f, -rotate_x));
	Set_Scale(Vector3::One * GAME_CONST.JT_SCALE[_isUsedJet]);
}