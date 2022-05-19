/**
 * @file WireStrategy.h
 * @brief C[ĢUé¢ĢīźNX
 * @author āV”DF
 * @date 2021/05/14
 */

#pragma once

//Oūé¾
class ObjWire;

class WireStrategy {
public:
	WireStrategy() {}
	virtual ~WireStrategy() {}

	virtual void Update(ObjWire* wire) = 0;
};