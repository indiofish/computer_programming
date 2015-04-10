#include <iostream>

int adder(int num1, int num2=1)
{
  return num1+num2;
}


int main(void)
{
  int a = 10, b =3;
  std::cout << adder(a,b) << std::endl;
  std::cout << adder(a) << std::endl;
  
  return 0;
}
