#include <iostream>

using namespace std; 

class Constructor
{
public:
  Constructor() {
    num1=0;
    num2=0;
  }
  Constructor(int n) {
    num1=n;
    num2=0;
  }
  Constructor(int n1, int n2) {
    num1=n1;
    num2=n2;
  }

  /*
   *Constructor(int n1=0, int n2=0) {
   *  num1=n1;
   *  num2=n2;
   *}
   */
  ~Constructor();
  

  void showData() const
  {
    std::cout << num1<<' ' <<num2 << std::endl;
  }

private:
  int num1;
  int num2;
};

int main(void)
{
  Constructor sc1;
  sc1.showData();

  Constructor sc2(100);
  sc2.showData();

  Constructor sc3(100,200);
  sc3.showData();
  return 0;
}
