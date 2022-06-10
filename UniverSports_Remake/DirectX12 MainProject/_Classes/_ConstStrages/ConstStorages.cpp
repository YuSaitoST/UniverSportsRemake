#include "ConstStorages.h"
#include "_Classes/_LoadCSV/LoadCSV.h"

void ConstStorageC::Initialize() {
	CSV::Schan(L"_Parameters\\GameProgressionParameter.csv",
		"%f,%f,%f,%f,%f,%f,%f,%f,%f",
		&gameParam_.TL_UI_DISPLAY,
		&gameParam_.TL_TIME_LOGO_DISPLAY,
		&gameParam_.TL_DEMO_PLAYBACK,
		&gameParam_.LB_MV_SCALE,
		&gameParam_.LB_TIME_AFTER_PREPARATION,
		&gameParam_.MN_TIME_HANDBALL,
		&gameParam_.FN_TIME_MOVE,
		&gameParam_.FN_TIME_DISPLAY,
		&gameParam_.FN_TIME_FADEOUT
	);

	float px, py;
	float hx, hy;
	CSV::Schan(L"_Parameters\\PlayersParameter.csv",
		"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
		&px,
		&py,
		&hx,
		&hy,
		&playerParam_.Player_FacingRight,
		&playerParam_.SCALE,
		&playerParam_.SPEED_MAX_NORMAL,
		&playerParam_.SPEED_MAX_BOOST,
		&playerParam_.SPEED[0],
		&playerParam_.SPEED[1],
		&playerParam_.TIME_RESPONE,
		&playerParam_.TIME_INVINCIBLE
	);

	CSV::Schan(L"_Parameters\\ThrusterParameter.csv",
		"%f,%f,%f,%f,%f,%f",
		&thrusterParam_.SCALE[0],
		&thrusterParam_.SCALE[1],
		&thrusterParam_.MOVEMENT_NOMAL,
		&thrusterParam_.MOVEMENT_ACCEL,
		&thrusterParam_.AMOUNT_OF_DECREASE,
		&thrusterParam_.AMOUNT_OF_RECOVERY
	);
	CSV::Schan(L"_Parameters\\BallParameter.csv",
		"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
		&ballParam_.MAX[0],
		&ballParam_.MAX[1],
		&ballParam_.MAX[2],
		&ballParam_.MAX[3],
		&ballParam_.MOD_SCALE,
		&ballParam_.COL_SCALE,
		&ballParam_.OBJ_SCALE,
		&ballParam_.SPEED_FLOAT,
		&ballParam_.SPEED_SHOT,
		&ballParam_.Z_CAUTCH
	);

	float wx, wy;
	CSV::Schan(L"_Parameters\\WireParameter.csv", "%f,%f", &wx, &wy);

	playerParam_.START_POS[0] = DirectX::XMFLOAT3(-px, py, 0.0f);
	playerParam_.START_POS[1] = DirectX::XMFLOAT3(px, py, 0.0f);
	playerParam_.START_POS[2] = DirectX::XMFLOAT3(-px, -py, 0.0f);
	playerParam_.START_POS[3] = DirectX::XMFLOAT3(px, -py, 0.0f);

	playerParam_.HAND_POS = DirectX::XMFLOAT2(hx, hy);

	wireParam_.POS[0] = DirectX::XMFLOAT3(-wx, wy, 0.0f);
	wireParam_.POS[1] = DirectX::XMFLOAT3(wx, wy, 0.0f);
	wireParam_.POS[2] = DirectX::XMFLOAT3(wx, -wy, 0.0f);
	wireParam_.POS[3] = DirectX::XMFLOAT3(-wx, -wy, 0.0f);
}