/**
 * @file AtEndCondition.h
 * @brief Q[ĢI¹šĢīźNX
 * @author āV”DF
 * @date 2021/06/04
 */

#pragma once

//Oūé¾
class CountTimer;

class AtEndCondition {
public:
	AtEndCondition() {}
	virtual ~AtEndCondition() {}

	virtual bool IsFined(CountTimer* timer) = 0;
};