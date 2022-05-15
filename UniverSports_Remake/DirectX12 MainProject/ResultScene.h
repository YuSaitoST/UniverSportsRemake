//
// TemplateScene.h
//

#pragma once

#include "Scene.h"
#include "_Classes/_SoundPlayer/SoundPlayer.h"
#include "_Classes/_MoviePlayer/MoviePlayer.h"
#include "_Classes/_UI/_BlackOut/BlackOut.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class ResultScene final : public Scene {
public:
	ResultScene();
	virtual ~ResultScene() { Terminate(); }

	ResultScene(ResultScene&&) = default;
	ResultScene& operator= (ResultScene&&) = default;

	ResultScene(ResultScene const&) = delete;
	ResultScene& operator= (ResultScene const&) = delete;

	// These are the functions you will implement.
	void Initialize() override;
	void LoadAssets() override;

	void Terminate() override;

	void OnDeviceLost() override;
	void OnRestartSound() override;

	NextScene Update(const float deltaTime) override;
	void Render() override;


private:
	void Render_WinChara();
	void Render_WinCName();

	float GetRectX(int number, int numbersMax, int wight);

	const int SERIALNUMBERS_MAX = 9;



	DX12::DESCRIPTORHEAP		descriptorHeap_;
	DX12::SPRITEBATCH			spriteBatch_;
	DX12::HGPUDESCRIPTOR		dx9GpuDescriptor_;

	std::vector<DX9::SPRITE>	sp_winPlayer_;

	DX9::SPRITE					sp_bg_tile_;
	DX9::SPRITE					sp_texWin_;
	DX9::SPRITE					sp_texPressB_;
	DX9::SPRITE					sp_texCrushing_;
	DX9::SPRITE					sp_playerName_;
	DX9::SPRITE					sp_number_;

	SoundPlayer*				bgm_;
	SoundPlayer*				se_decision_;
	MoviePlayer*				bg_movie_;
	BlackOut*					blackOut_;

	int							maxScore_;

	int							player_rect_x[2];
	int							oneDigit_x;
	int							twoDigit_x;

	bool						goNext_;
};

namespace SERIAL_PLAYER {
	const int		POS_X = 115;
	const int		POS_Y = 250;
	const int		RECT_X = 270;
	const int		RECT_Y = 135;
};
namespace SERIAL_NUMBER {
	const int		POS_X = 360;
	const int		POS_Y = 462;
	const int		RECT_X = 50;
	const int		RECT_Y = 75;
};