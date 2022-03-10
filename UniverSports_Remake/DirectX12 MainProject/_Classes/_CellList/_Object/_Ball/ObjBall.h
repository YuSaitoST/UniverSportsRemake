#pragma once

#include "_Classes/_CellList/_Object/ObjectBase.h"
#include "_State/BallState.h"
#include "_State/_Float/StFloat.h"
#include "_State/_Cautch/StCautch.h"

class ObjBall final : public ObjectBase {
public:
	enum STATE {
		FLOAT,
		CAUTCH,
		SHOT,
		GOAL,
		NONE_STATE
	};

public:
	ObjBall();
	ObjBall(Vector3 pos, float r);
	virtual ~ObjBall();

	virtual void Initialize(const int id);
	virtual void LoadAssets(std::wstring file_name) {};
	virtual void LoadAssets(DX9::MODEL& model);
	virtual void Update(const float deltaTime);
	virtual void Render() {};
	virtual void Render(DX9::MODEL& model);
	virtual void UIRender() {};

	void SwitchState(STATE state);
	void Moving(Vector3 power) { physics_->Moving(power); };
	void AddPower(Vector3 forward, float speed);
	void AssignPosition() {
		pos_ = physics_->GetCenterOfMassPosition();
	}
	void AssignTransform(Vector2 position, Vector2 forward) {
		pos_ = position;
		forward_ = forward;
	}

	bool IsInPlayerHands() const { return isInPlayerHands_; }

private:
	void SetTransforms();

	BallState* state_;
	DX9::MODEL model_;
	float pos_z_;  // 投げる際に動かす(予定、多分そうした方が見栄えいい)
	bool isInPlayerHands_;
};