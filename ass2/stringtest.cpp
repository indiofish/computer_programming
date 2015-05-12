#include <iostream>
#include "String.h"
using std::cout;
using std::endl;
using std::boolalpha;

int main() {
  String s1( "happy" );
  String s2( "birthday" ); 
  String s3;
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  // test overloaded equality and relational operators
  cout << boolalpha << "\n\nThe results of comparing s2 and s1:" << "\ns2 == s1 yields " <<
    ( s2 == s1 )
    << "\ns2 != s1 yields " << ( s2 != s1 )
    << "\ns2 > s1 yields " << ( s2 > s1 )
    << "\ns2 < s1 yields " << ( s2 < s1 )
    << "\ns2 >= s1 yields " << ( s2 >= s1 )
    << "\ns2 <= s1 yields " << ( s2 <= s1 )<<endl;
  //std::cout << s1(0,2) << std::endl;
  s1 += s2;
  s1 += " to you";
  std::cout << "here?" << std::endl;
  std::cout << s1 << std::endl;

  // test overloaded String empty (!) operator
  cout << "\n\nTesting !s3:" << endl;
  if ( !s3 ) {
    cout << "s3 is empty; assigning s1 to s3;" << endl; s3 = s1; 
    //this is causing error in free!
     //test overloaded assignment
    cout << "s3 is \"" << s3 << "\"\n"; 
  } 
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  std::cout << "test print till end" << std::endl;
  std::cout << s3(2) << std::endl;

  //test 
  String *s4Ptr = new String(s2);
  std::cout << "testing copy constructor" << std::endl;
  std::cout << *s4Ptr << std::endl;
  std::cout << s2[0] << std::endl;
  std::cout << "char is " << s1[0] << std::endl;
  s1[2] = 'z';
  std::cout << "after modification" << std::endl;
  std::cout << s1 << std::endl;
  std::cout << "test const subscript" << std::endl;
  std::cout << s2[3] << std::endl;

  std::cout << "Attempt to assign 'd' to s1[30] yields " << std::endl;
  s1[300] = 'd';

  return 0;
} // end main
