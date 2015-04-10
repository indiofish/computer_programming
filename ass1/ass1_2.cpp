#include <iostream>
#include <string>

using namespace std;

class myNum
{
public:
  myNum(int a) {
    num = a;
  }

  void setNumber(int a) {
    num = a;
  }
  int getNumber() {
    return num;
  }

  string split() {
    int digit = countMyDigit();
    int divisor = 1;
    int n = num;
    int i;
    string result;

    for (i = 0; i < digit-1; i++) {
      divisor *= 10;
    }

    for (i = 0; i < digit; i++) {
      result += (n/divisor) + 48;
      result += "   ";
      n = n%divisor;
      divisor = divisor / 10;
    }
    return result;
  }

private:
  int num;

  int countMyDigit() {
    int digits = 0;
    int n = num;
    while (n) {
        n /= 10;
        digits++;
    }
    return digits;
  }

};

int main(void)
{
  int input;
  std::cin >> input;
  myNum n(input);

  std::cout << n.split() << std::endl;
  return 0;
}
