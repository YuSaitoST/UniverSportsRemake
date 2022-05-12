#include "BitCalculation.h"

int BitCalculation::BitSlide(int bit) {
	bit = (bit | bit << 2) & 0x33;
	bit = (bit | bit << 1) & 0x55;
	return bit;
}

int BitCalculation::PointToMorton(Vector2 pos) {
	// 格子の1辺における分割数
	const int _CN = (int)std::pow(2, N_);

	// 格子の一辺の長さ
	const float _sx = 1280.0f / _CN;
	const float _sy = 720.0f / _CN;

	// 格子の座標
	const int _kx = (int)(pos.x / _sx);
	const int _ky = (int)(pos.y / _sy);

	// bit操作
	const int _bx = BitSlide(_kx);
	const int _by = BitSlide(_ky);

	// OR演算して返す
	return (_bx | (_by << 1));
}

// Level,IndexからMortonIndexを求める
int BitCalculation::GetIndex(int Level, int Index) {
	const int _CR = (int)std::pow(4, Level);  // Common ratio (公比)
	return (((_CR - 1) / (4 - 1)) + Index);  // 等比級数
}