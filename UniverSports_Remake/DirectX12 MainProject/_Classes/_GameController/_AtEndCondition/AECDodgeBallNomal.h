/**
 * @file AECDodgeBallNomal.h
 * @brief ドッジボールノーマルモードの終了条件クラス
 * @author 齋藤優宇
 * @date 2021/06/04
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "AtEndCondition.h"
#include "DontDestroyOnLoad.h"

class AECDodgeBallNomal : public AtEndCondition {
public:
	AECDodgeBallNomal() {}
	virtual ~AECDodgeBallNomal() {}

	/**
	* @brief ゲームが終了したかを返す
	* @return ゲームの終了状態
	*/
	virtual bool IsFined(CountTimer* timer) override { return DontDestroy->Survivor_.RemainingNumberOfPlayer() <= 1; }
};