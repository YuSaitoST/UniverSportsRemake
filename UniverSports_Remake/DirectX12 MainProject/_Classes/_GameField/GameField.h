/**
 * @file GameField.h
 * @brief 本編のフィールドクラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include "_Classes/_MoviePlayer/MoviePlayer.h"

class GameField {
public:
	GameField(float sp_z);
	virtual ~GameField() {}
	
	GameField(GameField&&) = delete;
	GameField& operator= (GameField&&) = delete;

	GameField(GameField const&) = delete;
	GameField& operator= (GameField const&) = delete;

	void LoadAsset();
	void Update();
	void Render();

private:
	//! 背景動画
	std::unique_ptr<MoviePlayer> movie_;
	
	//! ワイヤーの画像リスト
	std::vector<DX9::SPRITE> sp_wireList_;

	//! ワープホール画像
	DX9::SPRITE sp_hole_;

	//! 座標
	float sprite_z_;

};