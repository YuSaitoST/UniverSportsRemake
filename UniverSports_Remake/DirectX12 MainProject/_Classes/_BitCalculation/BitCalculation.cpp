#include "BitCalculation.h"

int BitCalculation::BitSlide(int b) {
	b = (b | b << 2) & 0x33;
	b = (b | b << 1) & 0x55;
	return b;
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