#include <iostream>
void Show(int num1, int num2=0)
{
  std::cout << num1 <<','<<num2 << std::endl;
}
void Show(int num1, char ch1)
{
  std::cout << num1 <<','<<ch1 << std::endl;
}

int main(void)
{
  std::cout << "[1,1] : " << std::endl;
  Show(1,1);
  std::cout << "[1,D] : " << std::endl;
  Show(1,'D');
  
  return 0;
}
