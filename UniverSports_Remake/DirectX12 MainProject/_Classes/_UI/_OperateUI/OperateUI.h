/**
 * @file OperateUI.h
 * @brief 操作説明クラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "Base/pch.h"
#include "Base/dxtk.h"
#include "_StateOpe/StateOpeBase.h"
#include "_StateOpe/_Open/OpeClose.h"
#include "_StateOpe/_Close/OpeOpen.h"

class OperateUI {
public:
	OperateUI();
	virtual ~OperateUI() {};

	void Initialize();
	void LoadAsset();
	void Update(const float deltaTime);
	void Render() const;

	void isPut();

	/**
	* @brief 現在の状態を返す
	* @return 表示状態
	*/
	int isState() const { return num_state_; };

	/**
	* @brief 表示状態を返す
	* @return 表示されていればtrue　されていなければfalse
	*/
	bool isDisplayed() const { return isDisplay_; };

private:
	/**
	* @brief アニメーションをオンにする
	*/
	void AnimateOn() { state_ = &st_open_; };

	/**
	* @brief アニメーションをオフにする
	*/
	void AnimateOff() { state_ = &st_close_; };

private:
	const int OPERATE_COUNT = 1;

	//!操作説明状態基底クラス
	OP_StateBase*	state_;

	//! 操作説明を表示させる状態
	OpeOpen			st_open_;

	//! 操作説明を閉じる状態
	OpeClose		st_close_;

	//! ゲームパッド操作説明画像
	DX9::SPRITE sp_gamepad_;

	//! ゲームパッド操作説明画像の座標
	DirectX::XMFLOAT3 pos_pad_;

	//! 現在の状態
	int num_state_;

	//! 表示状態
	bool isDisplay_;
};