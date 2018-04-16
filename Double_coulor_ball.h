#include<iostream>
#include<array>
#include<vector>

class Double_coulor_ball{
public:
  Double_coulor_ball();
  std::array<int,7> result() {return doubleCoulorBallResult;}
  int appearCount() {return appearCount;}
private:
  std::array<int,7> doubleCoulourBallResult;
  int appearCount;
};
