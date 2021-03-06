/**
 * @file TeamColor.h
 * @brief `[J[ĢīźNX
 * @author āV”DF
 * @date 2021/05/14
 */

#pragma once

class TeamColor {
public:
	TeamColor() {}
	virtual ~TeamColor() {}

	virtual void Initialize() = 0;
	virtual void LoadAssets() = 0;
	virtual void Render(int playerID) = 0;
};