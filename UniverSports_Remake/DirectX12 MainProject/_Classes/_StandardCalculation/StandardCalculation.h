/**
 * @file Serials.h
 * @brief ÄpIČvZ
 * @author āV”DF
 * @date 2021/05/14
 */

namespace StandardCalculation {

	template<typename Number> void ValueLoop(Number& num, Number min, Number max) {
		if (num < min)
			num = max;

		if (max < num)
			num = min;
	}

}  //namespace StandardCalculation