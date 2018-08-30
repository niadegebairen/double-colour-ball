#include "Double_color_ball.h"
#include<vector>
#include<random>
#include<algorithm>

Double_color_ball::Double_color_ball() {
	std::uniform_int_distribution<unsigned> u(1, 16), u1(0, 32), u2(0, 31), u3(0, 30), u4(0, 29), u5(0, 28), u6(0, 27);
	std::random_device ge;
	std::vector<unsigned>a{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };
	auto b1 = u1(ge), b2 = u2(ge), b3 = u3(ge), b4 = u4(ge), b5 = u5(ge), b6 = u6(ge);
	doubleColorBallResult[0] = a[b1];
	a.erase(a.begin() + b1);
	doubleColorBallResult[1] = a[b2];
	a.erase(a.begin() + b2);
	doubleColorBallResult[2] = a[b3];
	a.erase(a.begin() + b3);
	doubleColorBallResult[3] = a[b4];
	a.erase(a.begin() + b4);
	doubleColorBallResult[4] = a[b5];
	a.erase(a.begin() + b5);
	doubleColorBallResult[5] = a[b6];
	doubleColorBallResult[6] = u(ge);
	std::sort(doubleColorBallResult.begin(), doubleColorBallResult.begin() + 6);
	appearanceCount = 1;
}


bool unfrequent(const Double_color_ball &a, const Double_color_ball &b) {
	        return a.AppearanceCount() > b.AppearanceCount();
}
