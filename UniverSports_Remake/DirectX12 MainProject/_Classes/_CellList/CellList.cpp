#include "CellList.h"
#include "_Cell/Cell.h"
#include "_Classes/_CellList/_BitCalculation/BitCalculation.h"
#include <cassert>

CellList::CellList() {
	cpList_				= new Cell[BitCalculation::GetIndex(N + 1, 0)];
}

CellList::~CellList() {
	delete[] cpList_;
}

/**
* @brief 空間を登録する
* @param cp 空間
*/
void CellList::PushList(Cell* cp) {
	int _m				= cp->numbers_.MsIndex_;
	int _iMax			= BitCalculation::GetIndex(N + 1, 0);

	assert((0 <= _m) && (_m < _iMax) + "CellList::PushList : 空間リスト外です");

	cp->next_			= cpList_[_m].next_;		// 自分の次のCellを登録
	cp->prev_			= &cpList_[_m];				// 自分のCellの参照を登録
	cp->next_->prev_	= cp->prev_->next_ = cp;	// 「自分の次の前」と「自分の前の次」に自分のCellを登録
}

/**
* @brief 指定した空間内での衝突判定
* @param index 空間のインデックス
* @param m 衝突状態を調べたい物体
* @return 衝突した物体(衝突していない場合はnullptr)
*/
ObjectBase* CellList::GetCollision(int index, ObjectBase* m) {
	ObjectBase* _mp_opponent = nullptr;

	// 指定したindexの空間内
	for (Cell* _cp = cpList_[index].next_, *_np = nullptr;
		_cp != &cpList_[index];) 
	{
		_np = _cp->next_;

		_mp_opponent = m->GetCollision(_cp->mp_);

		if (_mp_opponent != nullptr && m != _mp_opponent) {
			// 同じ種類同士の衝突なら無視
			if (m->myObjectType() == _cp->mp_->myObjectType())
				continue;

			return _mp_opponent;
		}

		_cp = _np;
	}

	return nullptr;
}