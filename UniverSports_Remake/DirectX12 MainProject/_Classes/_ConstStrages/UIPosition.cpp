#include "UIPosition.h"

void US2D::Pos::Initialize() {
	CSV::Schan(L"_Parameters\\_UI\\TitleUIPosition.csv", "%f,%f,%f,%f,%f,%f",
		&title_.LeftArrowX,			&title_.RightArrowX,		&title_.ArrowY,	
		&title_.TextX,				&title_.TextY[0],			&title_.TextY[1]
	);
	CSV::Schan(
		L"_Parameters\\_UI\\LobbyUIPosition.csv",
		"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
		&lobby_.ARROW_L_X[0],	&lobby_.ARROW_R_X[0],
		&lobby_.ARROW_L_X[1],	&lobby_.ARROW_R_X[1],
		&lobby_.ARROW_L_X[2],	&lobby_.ARROW_R_X[2],
		&lobby_.ARROW_L_X[3],	&lobby_.ARROW_R_X[3],	&lobby_.ARROW_Y,
		&lobby_.PICON_X[0],		&lobby_.PICON_X[1],		&lobby_.PICON_X[2],		&lobby_.PICON_X[3],		&lobby_.PICON_Y,
		&lobby_.TEAM_COL_X[0],	&lobby_.TEAM_COL_X[1],	&lobby_.TEAM_COL_X[2],	&lobby_.TEAM_COL_X[3],	&lobby_.TEAM_COL_Y,
		&lobby_.INPUT_X[0],		&lobby_.INPUT_X[1],		&lobby_.INPUT_X[2],		&lobby_.INPUT_X[3],		&lobby_.INPUT_Y,
		&lobby_.ENTRY_X[0],		&lobby_.ENTRY_X[1],		&lobby_.ENTRY_X[2],		&lobby_.ENTRY_X[3],		&lobby_.ENTRY_Y,
		&lobby_.VIEW_X, &lobby_.VIEW_Y,					&lobby_.VIEW_W,			&lobby_.VIEW_H
	);
	float LeftX, RightX, UpY, DownY;
	CSV::Schan(L"_Parameters\\_UI\\MainUIPosition.csv", "%f,%f,%f,%f,%i,%f,%f",
		&LeftX, &RightX, &UpY, &DownY, 
		&main_.LIFEICON_SIZE, 
		&main_.TIMER.x, &main_.TIMER.y
	);
	main_.LIFEICON_LPOS[0] = DirectX::XMFLOAT3(LeftX,	UpY,	0.0f);
	main_.LIFEICON_LPOS[1] = DirectX::XMFLOAT3(RightX,	UpY,	0.0f);
	main_.LIFEICON_LPOS[2] = DirectX::XMFLOAT3(LeftX,	DownY,	0.0f);
	main_.LIFEICON_LPOS[3] = DirectX::XMFLOAT3(RightX,	DownY,	0.0f);
	CSV::Schan(L"_Parameters\\_UI\\ResultUIPosition.csv", "%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f",
		&result_.NUMBER_POS_X,	&result_.NUMBER_POS_Y,
		&result_.NUMBER_RECT_X, &result_.NUMBER_RECT_Y, &result_.NUMBER_MAX,
		&result_.PLAYER_POS_X,	&result_.PLAYER_POS_Y,
		&result_.PLAYER_RECT_X, &result_.PLAYER_RECT_Y, &result_.PLAYER_MAX,
		&result_.WINNER_A_X,	&result_.WINNER_B_X,	&result_.WINNERNAME_SPACE
	);
}
