/**
 * @file PlayerList.h
 * @brief プレイヤーのリストクラス
 * @author 齋藤優宇
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	インクルードファイル
 //------------------------------------------------------------------------------
#include <vector>
#include "ObjPlayer.h"

//前方宣言
class BallsInstructor;

class PlayerList {
public:
	PlayerList();
	virtual ~PlayerList();

	void Initialize();
	void LoadAssets();
	void Update(const float deltaTime);
	void RenderModel();
	void RenderSprite();
	void RenderTransparency();

	void AddWorld(btDynamicsWorld* physics_world_);
	void RemoveWorld(btDynamicsWorld* physics_world_);

	void SetInstructors(BallsInstructor* blInstructor, PlayersInstructor* plInstuructor);

	int PlayerLife(int index);

	/**
	* @brief プレイヤーリストを返す
	* @return プレイヤーリスト
	*/
	std::vector<ObjPlayer*> GetList() const { return list_; }

private:
	std::vector<ObjPlayer*> list_;
};