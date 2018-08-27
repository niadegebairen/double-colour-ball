#include<vector>
#include<random>
#include<algorithm>
#include<fstream>
#include<map>
#include<array>
#include<iostream>
#include"Double_color_ball.h"

std::fstream input("set2");

int main(){
	unsigned red1,red2,red3,red4,red5,red6,blue;
	size_t count;
	std::map<std::array<unsigned,7>,size_t> doubleColorBallSet;
	while(input>>red1>>red2>>red3>>red4>>red5>>red6>>blue>>count){
		doubleColorBallSet[{red1,red2,red3,red4,red5,red6,blue}]=count;
	}
	input.close();
	std::cout<<doubleColorBallSet.size()<<std::endl;
	for(size_t i=0;i!=1000000000;++i){
		std::uniform_int_distribution<unsigned> u(1, 16), u1(0, 32), u2(0, 31), u3(0, 30), u4(0, 29), u5(0, 28), u6(0, 27);
		std::random_device ge;
		std::vector<unsigned>a{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };
		auto b1 = u1(ge), b2 = u2(ge), b3 = u3(ge), b4 = u4(ge), b5 = u5(ge), b6 = u6(ge);
		std::array<unsigned,7> signal;
		signal[0] = a[b1];
		a.erase(a.begin() + b1);
		signal[1] = a[b2];
		a.erase(a.begin() + b2);
		signal[2] = a[b3];
		a.erase(a.begin() + b3);
		signal[3] = a[b4];
		a.erase(a.begin() + b4);
		signal[4] = a[b5];
		a.erase(a.begin() + b5);
		signal[5] = a[b6];
		signal[6] = u(ge);
		std::sort(signal.begin(),signal.begin() + 6);
		++doubleColorBallSet[signal];
	}
	std::cout<<doubleColorBallSet.size()<<std::endl;
	std::ofstream output("set2");
	for(auto &once:doubleColorBallSet){
		for(auto &value:once.first){
			output<<value<<" ";
		}
		output<<once.second<<std::endl;
	}
	std::vector<Double_color_ball> resultset;
	for(auto &once:doubleColorBallSet){
		resultset.emplace_back(once.first,once.second);
	}
	std::sort(resultset.begin(),resultset.end(),unfrequent);
	for(auto iter=resultset.begin();iter!=resultset.begin()+100;++iter){
		for(auto &a:iter->Result()){
			std::cout<<a<<" ";
		}
		std::cout<<iter->AppearanceCount()<<std::endl;
	}	
	std::cout<<resultset.size()<<std::endl;
	return 0;
