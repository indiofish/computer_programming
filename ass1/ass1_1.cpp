#include <iostream>
class printChar
{
public:
  void setChar(char a) {
    character = a;
  }

  int castToInt()
  {
    return static_cast<int>(character);
  }

private:
  char character;
};

int main(void)
{
  char input;
  printChar p;
  while(true) {
    std::cin >> input;
    p.setChar(input);
    std::cout << p.castToInt() << std::endl;
  }
  return 0;
}
