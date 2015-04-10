#include <iostream>
#define AMERICANO 200
#define CAFFELATTE 400

class Vending
{
  private:
    int cups;
    bool isEnoughMoney(int kindOfCoffee, int money) 
    {
      switch (kindOfCoffee) 
      {
        case 1:
          return (money>=AMERICANO? true:false);
        case 2:
          return (money>=CAFFELATTE? true:false);
        default:
          return false;
      }
    }

  public:
    void makeNcupOfCoffee(int kindOfCoffee, int money) {
      if (kindOfCoffee > 2) 
        std::cout << "No Such Coffee dude!" << std::endl;
      else if(isEnoughMoney(kindOfCoffee, money)==true) {
        cups = money / (200 * kindOfCoffee);
        std::cout << cups << "cups" << std::endl;
      }
      else 
        std::cout << "Not enough money, dude!" << std::endl;
      return;
    }
};


int main(int argc, const char *argv[])
{
  int money;
  int kindOfCoffee;
  Vending machine;
  std::cin >> kindOfCoffee;
  std::cin >> money;
  machine.makeNcupOfCoffee(kindOfCoffee, money);

  return 0;
}
