/**
 * @file SelectArrows.h
 * @brief IšĢ¶EīóNX
 * @author āV”DF
 * @date 2021/05/14
 */

#pragma once

 //------------------------------------------------------------------------------
 //	CN[ht@C
 //------------------------------------------------------------------------------
#include "Base/pch.h"
#include "Base/dxtk.h"

class SelectArrows {
public:
	SelectArrows();
	virtual ~SelectArrows() {};

	void Initialize(float x_right, float x_left);
	void LoadAssets();
	void LoadAssets(DX9::SPRITE right, DX9::SPRITE left);
	bool Update(const int index);
	void Render(float alpha, float posY);

private:
	void Animations(float& scale);

	/**
	 * @brief TCYšźčlÜÅgå·é
	 * @param scale TCY
	*/
	void GetBigger(float& scale) { scale = std::min(scale + SPEED_BIGGER, SCALE_MAX); }

	/**
	 * @brief TCYšźčlÜÅk¬·é
	 * @param scale TCY
	*/
	void GetSmaller(float& scale) { scale = std::max(1.0f, scale - SPEED_SMALLER); }

private:
	const float RECT		= 12.5f;
	const float SCALE_MAX	= 1.5f;
	const float SPEED_BIGGER = 0.15f;
	const float SPEED_SMALLER = 0.1f;

private:
	/**
	 * @enum INPUT_SELECT
	 * üĶóŌ
	*/
	enum INPUT_SELECT { AL_RIGHT, AL_LEFT, AL_NONE };

	INPUT_SELECT	input_;			//! üĶóŌ

	DX9::SPRITE		sp_right_;		//! EīóĢę
	DX9::SPRITE		sp_left_;		//! ¶īóĢę

	float			pos_right_x_;	//! EīóĢXĄW
	float			pos_left_x_;	//! ¶īóĢXĄW
	float			scale_right_;	//! EīóĢTCY
	float			scale_left_;	//! ¶īóĢTCY
	bool			isFinBigger;	//! gåĢI¹óŌ
	bool			isFinSmaller;	//! k¬ĢI¹óŌ
};