#include <iostream>
//using namespace std;

char swapCase(char alphabet) {
  if ('a'<=alphabet && alphabet <= 'z') {
    return alphabet -= 32;
  } else if ('A' <= alphabet && alphabet <= 'Z') {
    return alphabet += 32;
  } else {
    return alphabet;
  }
}

int main(void)
{
  char alphabet;
  bool out = false;

  while (out==false)
  {
    std::cout << "Enter Capital or Small (0 for exit): ";
    std::cin >> alphabet;

    if (alphabet == '0') {
      std::cout << "exiting" << std::endl;
      break;
    } else {
      std::cout << "input: " << alphabet;
      std::cout << " result: " << swapCase(alphabet) << std::endl;
    }
  }
  return 0;
}

