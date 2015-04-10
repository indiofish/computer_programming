#include <iostream>

class Loopadder
{
  private:
    int start;
    int result;

  public:
    Loopadder(int i)
    {
      start = i;
      result = 0;
    }
    int SumUpTo(int range)
    {
      for (int i = 1; i <= range; i++) {
      //for (int i = start; i <= range; i++) {
        result += i;
      }
      return result;
    }
};

int main(int argc, const char *argv[])
{
  Loopadder *adder = new Loopadder(1);
  //Loopadder adder;
  std::cout << (*adder).SumUpTo(100) << std::endl;
  return 0;
}
