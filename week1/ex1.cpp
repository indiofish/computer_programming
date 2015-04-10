#include <iostream>
#include <string>
using namespace std;

class Item {
  public:
    string title;
    double price;
    double SalePrice() { return (price * 0.9); }
    bool isAvailable() { return (inStockQuantity > 0); }
  private:
    int inStockQuantity;
};

int main(int argc, const char *argv[])
{
  Item a;
  a.title = "comp";
  a.price = 2000;

  std::cout << a.title << std::endl;
  std::cout << a.SalePrice() << std::endl;
  return 0;
}
