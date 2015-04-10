#include <iostream>
//#include <cstring>
#include <string.h>
#include <assert.h>
using namespace std;

class String {
  public:
    String(const char *s) {
      len = strlen(s);
      str = new char[len+1];
      assert(str != 0);
      strcpy(str,s);
    }
    ~String() {delete [] str; }
      void showStr()
      {
        std::cout << str << std::endl;
      }
  private:
      int len;
      char *str;
};

int main(int argc, const char *argv[])
{
  String str = String("str");
  str.showStr();

  return 0;
}
