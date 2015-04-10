#include <iostream>

void coffeeMaker(int mny, int type)
{
  std::cout << mny/200 << "cups of coffee" << std::endl;
}

void coffeeMaker(int mny, int type, int extra)
{
  std::cout << (mny/200)/extra << "cups of coffee" << std::endl;
}

int main(void)
{
  int money=0;
  int type = 0;
  bool isAddShot = 0;
  int shot = 0;
  std::cout << "Money in!" << std::endl;
  std::cin >> money;
  std::cout << "type in!" << std::endl;
  std::cin >> type;
  std::cout << "add shot?(yes:1, no:2)" << std::endl;
  std::cin >> isAddShot;

  if (isAddShot==1) {
    coffeeMaker(money,type);
  }
  else  
    coffeeMaker(money,type,shot);
  return 0;
}
