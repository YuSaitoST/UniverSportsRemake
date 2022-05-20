/**
 * @file GameController.h
 * @brief ゲームの進行管理クラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "Scene.h"
#include "DontDestroyOnLoad.h"
#include "_Classes/_UI/_CountTimer/CountTimer.h"
#include "_Classes/_UI/_CountDown/CountDown.h"
#include "_Classes/_UI/_BlackOut/BlackOut.h"
#include "_Classes/_UI/_Finish/Finish.h"
#include "_Classes/_SoundPlayer/SoundPlayer.h"

class GameController {
public:
	GameController();
	virtual ~GameController();

	void Initialize();
	void LoadAssets();
	NextScene Update(const float deltaTime);
	void Render();
	bool GameFined();

	static bool GamePlay() { return gameStart_; }

private:
	int RemainingNumberOfPlayer();
	int RemainingOfTeam();

	const float TIME_COUNT		= 4.2f;
	const float TIME_LIMIT[4]	= { 0.0f, 0.0f, 120.0f, 0.0f };
	const float	SPEED_FADE[3]	= { 51.0f, 510.0f, 0.0f };

	//! タイマー
	CountTimer*		timer_;

	//! 開始前カウントダウン
	CountDownUI*	countDown_;

	//! ブラックアウト
	BlackOut*		blackOut_;

	//! 終了時テキスト
	Finish*			ui_finish_;

	//! 終了時SE
	SoundPlayer*	se_whistle_;

	//! ゲームの制限時間
	float			startTime_;

	//! ゲームの進行状態フラグ
	static bool		gameStart_;
};