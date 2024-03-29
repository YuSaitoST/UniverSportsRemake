/**
 * @file TextBase.h
 * @brief 選択肢テキストの基底クラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "Base/pch.h"
#include "Base/dxtk.h"

class TextBase {
public:
	TextBase() : scale_(0.0f) {};
	virtual ~TextBase() {};

	virtual void Initialize(int modeID, DirectX::XMFLOAT3 pos) = 0;
	virtual void LoadAsset(std::wstring file_name) = 0;
	virtual void Render(float alpha) = 0;

	/**
	 * @brief 拡大演出
	*/
	inline void GetBigger(const float deltaTime) { scale_ = std::min(scale_ + deltaTime, SCALE_MAX); };

	/**
	 * @brief 縮小演出
	*/
	inline void GetSmaller(const float deltaTime) { scale_ = std::max(scale_ - deltaTime, SCALE_MIN); };

protected:
	const float SCALE_MAX = 1.35f;
	const float SCALE_MIN = 1.0f;
	const float CENTER_X = 200.0f;
	const float CENTER_Y = 50.0f;

protected:
	//! テキスト画像
	DX9::SPRITE sprite_;

	//! テキスト座標
	DirectX::XMFLOAT3 position_;
	
	//! テキストサイズ
	float scale_;
};