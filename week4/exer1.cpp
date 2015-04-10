#include <iostream>

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap(char *a, char *b)
{
  char tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void)
{
  int num1 = 10, num2 = 20;
  swap(&num1, &num2);
  std::cout << num1<<' ' <<num2 << std::endl;

  char ch1 = 'A', ch2 = 'Z';
  swap(&ch1, &ch2);
  std::cout << ch1<<' ' <<ch2 << std::endl;
  return 0;
}
