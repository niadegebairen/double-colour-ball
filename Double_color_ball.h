#ifndef DOUBLE_H
#define DOUBLE_H
#include<array>
class Double_color_ball {
	public:
	Double_color_ball();
	Double_color_ball(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, unsigned a6, unsigned b) :
		doubleColorBallResult({ a1, a2, a3, a4, a5, a6, b} ) {}
	Double_color_ball(std::array<unsigned,7> ua,size_t count):
		doubleColorBallResult(ua),appearanceCount(count) {}
	std::array<unsigned, 7> Result() const { return doubleColorBallResult; }
	void AppearOnceAgain()  { ++appearanceCount; }
	size_t AppearanceCount() const { return appearanceCount; }
	private:
	std::array<unsigned, 7> doubleColorBallResult;
	size_t appearanceCount{ 0 };
};

bool unfrequent(const Double_color_ball&, const Double_color_ball&);
#endif
