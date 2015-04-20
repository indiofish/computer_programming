#include <iostream>

class shop
{
  public:
    //default price
    shop(double p0=2.98, double p1=4.50, double p2=9.98, double p3=4.49, double p4=6.87)
    {
      itemPrice[0] = p0;
      itemPrice[1] = p1;
      itemPrice[2] = p2;
      itemPrice[3] = p3;
      itemPrice[4] = p4;
      currProfit = 0;
    }
    ~shop(){}

    void sells(int item, int quantity) {
      if (quantity >= 0 && item <= 5 && item >= 1) {
        currProfit += quantity * itemPrice[item-1];
      }
      else
        std::cout << "Wrong Order" << std::endl;
      return;
    }

    double grossProfit() {
      return currProfit;
    }

  private:
    double itemPrice[5];
    double currProfit;
    /* data */
};

int main(void)
{
  int item = 0, quantity = 0;
  shop myShop(2.98,4.50,9.98,4.49,6.87);
  
  while (true) {
    std::cout << "Which item would you like to order?" << std::endl;
    std::cin >> item;
    if (item == -1) 
      break;
    std::cout << "How many of them?" << std::endl;
    std::cin >> quantity;
    if (quantity == -1) 
      break;

    myShop.sells(item,quantity);
  }
  std::cout << "\nYou earned $" << myShop.grossProfit() << std::endl;

  return 0;
}
