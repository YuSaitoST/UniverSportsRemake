#pragma once

#include <btBulletDynamicsCommon.h>
#include "Base/pch.h"
#include "_Classes/_ConstStrages/ConstStorages.h"

using namespace DirectX;

class btObject {
public:
	btObject(SimpleMath::Vector3 pos);
	virtual ~btObject();

	void SetTransform(SimpleMath::Vector3 pos, SimpleMath::Vector3 rotate);
	void Moving(SimpleMath::Vector3 power);
	void LimitSpeed();

	inline btRigidBody* Get_RigidBody() const { return bt_body_; };
	
	inline SimpleMath::Vector2 GetCenterOfMassPosition() {
		const SimpleMath::Vector3 pos = (XMFLOAT3)bt_body_->getCenterOfMassPosition();
		return SimpleMath::Vector2(pos.x, pos.y);
	}

	inline SimpleMath::Vector2 GetLinearVelocity() {
		const SimpleMath::Vector3 vel = (XMFLOAT3)bt_body_->getLinearVelocity();
		return SimpleMath::Vector2(vel.x, vel.y);
	}

	inline void SetCenterOfMassTransform(SimpleMath::Vector3 position, SimpleMath::Vector3 rotate) {
		btTransform transform = btTransform(*(btQuaternion*)&rotate, *(btVector3*)&position);
		bt_body_->setCenterOfMassTransform(transform);
	}

	inline void SetLinerVelocity(SimpleMath::Vector3 forward) {
		bt_body_->setLinearVelocity(*(btVector3*)&forward);
	}

	inline void ResetVelocity() {
		btVector3 _vec(0.0f, 0.0f, 0.0f);
		bt_body_->setLinearVelocity(_vec);
		bt_body_->setAngularVelocity(_vec);
	}

private:
	btCollisionShape*		bt_collision_;
	btDefaultMotionState*	bt_state_;
	btRigidBody*			bt_body_;

	SimpleMath::Vector3		velocity_;
};