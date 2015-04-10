#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void swap(int *a, int *b);
void swap(char *a, char *b);

int main(void)
{
  int a, b;
  char c, d;
  std::cout << "Put two numbers for swapping" << std::endl;
  std::cin >> a;
  std::cin >> b;
  std::cout << "Put two characters for swapping" << std::endl;
  std::cin >> c;
  std::cin >> d;
  std::cout << "Result" << std::endl;
  swap(&a,&b);
  swap(&c,&d);
  std::cout << a <<" "<< b << std::endl;
  std::cout << c <<" "<< d << std::endl;
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void swap(char *a, char *b)
{
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
