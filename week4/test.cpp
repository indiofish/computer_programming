#include <iostream>

int num = 1;

namespace AAA
{
  int num = 5;

  namespace BBB
  {
    int num = 4;

    namespace CCC
    {
      int num = 3;
      void print()
      {
        std::cout << num << std::endl;
        std::cout << ::num << std::endl;
      }
    }
  }
}

int main(void)
{
  AAA::BBB::CCC::print();
  return 0;
}
