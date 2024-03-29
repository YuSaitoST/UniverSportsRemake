/**
 * @file US2DLayer.h
 * @brief 各シーンに用いる2D素材のレイヤー指定
 * @author 齋藤優宇
 * @date 2021/05/14
 */

namespace US2D {
	namespace Layer {
		/**
		* @enum TITLE
		* タイトル内で用いる2D素材のレイヤー
		*/
		enum class TITLE {
			//BlackOut
			UI_TEXT = 1,
			UI_OPERATE,
			//Arrow
			BG_DEMO = 4,
			BG_BACK
		};

		/**
		* @enum LOBBY
		* ロビー内で用いる2D素材のレイヤー
		*/
		enum class LOBBY {
			//BlackOut
			UI_ENTRY = 1,
			UI_DECISIONS,
			//Arrow
			UI_INFO_ICON = 4,
			UI_PLAYERICON,
			UI_TEAMCOLOR,
			BG_MOVIE,
			BG_SPRITE
		};

		/**
		* @enum MAIN
		* メイン内で用いる2D素材のレイヤー
		*/
		enum class MAIN {
			UI_FINISH = -9999,
			//BlackOut
			UI_COUNTDOWN = -9997,
			UI_LIFEICON,
			UI_HOLE,
			UI_GAUGE = 1,
			UI_GAUGE_FRAME,
			UI_TIMER,
			UI_WIRE,
			BG_MOVIE = 9999
		};

		/**
		* @enum RESULT
		* リザルト内で用いる2D素材のレイヤー
		*/
		enum class RESULT {
			UI_RESULT = 1,
			UI_WINNERTEXT,
			UI_WINNER,
			UI_SCORETEXT,
			UI_SCORE,
			UI_GO_TITLE,
			BG_SPRITE,
			BG_MOVIE
		};

		/**
		* @enum 
		* 複数のシーンで用いる2D素材のレイヤー
		*/
		enum class GENERIC {
			BLACKOUT = -9998,
			UI_ARROW = 3
		};

	}  //namespace Layer

}  //namespace US2DLayer