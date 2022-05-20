#include "ObjectBase.h"
#include "_Classes/_CellList/_Cell/Cell.h"

ObjectBase::ObjectBase() {
	SetMember(NONE_OBJ_ID, NONE_COLLI_TYPE, Vector3::Zero, 0.0f);
}

ObjectBase::ObjectBase(OBJ_TYPE kind, COLLI_TYPE collision, Vector3 pos, float r) {
	SetMember(kind, collision, pos, r);
}

ObjectBase::~ObjectBase() {
	if (cp_ != nullptr) {
		cp_->Remove();
		delete cp_;
	}
}

void ObjectBase::SetMember(OBJ_TYPE kind, COLLI_TYPE collision, Vector3 pos, float r) {
	this->obj_type_ = kind;
	this->pos_.x = pos.x;
	this->pos_.y = pos.y;
	if (this->cp_ == nullptr)
		this->cp_ = new Cell(this);  // 所属する空間を割り当てるため

	rotate_ = Vector2::Zero;
	forward_ = Vector2::Zero;
	collision_ = new bdCollision(collision);
}

ObjectBase* ObjectBase::GetCollision(ObjectBase* m) {
	OBJ_TYPE type = m->myObjectType();
	if (this->obj_type_ == type)
		return nullptr;

	if (this->obj_type_ != OBJ_TYPE::WIRE) {
		//自分がプレイヤー

		if (m->myObjectType() != OBJ_TYPE::WIRE) {
			//球体同士の衝突判定(ボールとプレイヤー)
			if (this->collision_->GetBoundingSph().Intersects(m->collision_->GetBoundingSph())) {
				return m;
			}
		}
		else {
			//球体と直方体の衝突判定(ボールorプレイヤーとワイヤー)
			if (this->collision_->GetBoundingSph().Intersects(m->collision_->GetBoundingBox())) {
				return m;
			}
		}
	}
	else {
		//自分がワイヤー
		//相手が球体と確定している
		if (this->collision_->GetBoundingBox().Intersects(m->collision_->GetBoundingSph())) {
			return m;
		}
	}

	return nullptr;
}

void ObjectBase::UpdateToMorton() {
	// 存在するなら、所属空間の更新をする
	if (cp_ != nullptr)
		cp_->UpdateToMorton();
}

ObjectBase* ObjectBase::GetHitObject() {
	return cp_->GetCollision();  // 上方、同レベル、下方の3方向を調べる(四分木探索)
}