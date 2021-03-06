/**
 * @file BallList.h
 * @brief ボールのリストクラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include <vector>
#include "ObjBall.h"

class BallList {
public:
	BallList();
	virtual ~BallList();

	void Initialize();
	void LoadAssets();
	void Update(const float deltaTime);
	void Render();
	void AddWorld(btDynamicsWorld* physics_world_);
	void RemoveWorld(btDynamicsWorld* physics_world_);

	/**
	* @brief ボールリストを返す
	* @return ボールリスト
	*/
	std::vector<ObjBall*> GetList() const { return list_; }

private:
	std::vector<ObjBall*> list_;
	DX9::MODEL model_;
	DX9::SHADER shader_;
	int N_BALL;
};