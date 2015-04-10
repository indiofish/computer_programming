#include <iostream>

int main(int argc, const char *argv[])
{
  enum season {me, he, she, her, man, le, ddf, wer, er, qwer, qwert, erewrwr, erwerw, werioj,qruyoqru,qewrqwryo,sdfoaysfoiaf,adfoasdyfosdf,erer, erwer, erwre,qrwer, dfdf,sfsf,werwer,qweqe,qeqweqwe,qweqeqew,qewew,erwrqwr,wewqrqwr,qweafdf,asdfasff,safasf,erwrwer, DUDE, HI,SPRING, SUMMER, FALL, WINTER};
  class Student {
    public:
      int id;
      int age;
      int foo;
      int bar;
  };

  std::cout << "size of long double: " << sizeof(long double) << std::endl;
  std::cout << "size of double: " << sizeof(double) << std::endl;
  std::cout << "size of float: " << sizeof(float) << std::endl;
  std::cout << "size of unsigned long int: " << sizeof(unsigned long int) 
    << std::endl;
  std::cout << "size of long int: " << sizeof(long int) << std::endl;
  std::cout << "size of unsigned int: " << sizeof(unsigned int) 
    << std::endl;
  std::cout << "size of int: " << sizeof(int) << std::endl;
  std::cout << "size of unsigned short int: " << sizeof(unsigned short int) << std::endl;
  std::cout << "size of short int: " << sizeof(short int) << std::endl;
  std::cout << "size of unsigned char: " << sizeof(unsigned char) << std::endl;
  std::cout << "size of char: " << sizeof(char) << std::endl;
  std::cout << "size of bool: " << sizeof(bool) << std::endl;
  std::cout << "size of enum season: " << sizeof(season) << std::endl;
  std::cout << "size of class Student: " << sizeof(Student) << std::endl;
  return 0;
}
