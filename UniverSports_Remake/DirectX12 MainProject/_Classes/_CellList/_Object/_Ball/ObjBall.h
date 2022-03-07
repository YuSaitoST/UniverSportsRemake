#pragma once

#include "_Classes/_CellList/_Object/ObjectBase.h"

class ObjBall final : public ObjectBase {
public:
	ObjBall();
	ObjBall(Vector3 pos, float r);
	virtual ~ObjBall();

	virtual void Initialize(const int id);
	virtual void LoadAssets(std::wstring file_name) {};
	virtual void LoadAssets(DX9::MODEL model);
	virtual void Update(const float deltaTime);
	virtual void Render();
	virtual void UIRender() {};

	void Moving(Vector3 power) { physics_->Moving(power); };
	void AssignPosition() {
		pos_ = physics_->GetCenterOfMassPosition();
	}

private:
	void SetTransforms();

	DX9::MODEL model_;
	float pos_z_;  // 投げる際に動かす(予定、多分そうした方が見栄えいい)
};