#include <iostream>
int price = 1000;

void discout()
{
  int price = 2000;
  std::cout << price * 0.7 << std::endl;
  std::cout << ::price * 0.7 << std::endl;
}

int main(void)
{
  discout();
  return 0;
}
