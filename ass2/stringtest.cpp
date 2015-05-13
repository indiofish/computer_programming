#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
#include "String.h"

int main() {
String s1( "happy" );
const String s2( " birthday" ); 
String s3;

// test overloaded equality and relational operators
cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
<< "\"; s3 is \"" << s3 << '\"'
<< boolalpha << "\n\nThe results of comparing s2 and s1:" << "\ns2 == s1 yields " <<
( s2 == s1 )
<< "\ns2 != s1 yields " << ( s2 != s1 )
<< "\ns2 > s1 yields " << ( s2 > s1 )
<< "\ns2 < s1 yields " << ( s2 < s1 )
<< "\ns2 >= s1 yields " << ( s2 >= s1 )
<< "\ns2 <= s1 yields " << ( s2 <= s1 );

// test overloaded String empty (!) operator
cout << "\n\nTesting !s3:" << endl;

if ( !s3 ) {
cout << "s3 is empty; assigning s1 to s3;" << endl; s3 = s1; // test overloaded assignment
cout << "s3 is \"" << s3 << "\""; 
} // end if

// test overloaded String concatenation operator 
cout << "\n\ns1 += s2 yields s1 = ";
s1 += s2; // test overloaded concatenation 
cout << s1;

// test conversion constructor
cout << "\n\ns1 += \" to you\" yields" << endl; s1 += " to you";
cout << "s1 = " << s1 << "\n\n";

// test overloaded function call operator () for substring
cout << "The substring of s1 starting at\n"
<< "location 0 for 14 characters, s1(0, 14), is:\n" << s1( 0, 14 ) << "\n\n";

// test substring "to-end-of-String" option
cout << "The substring of s1 starting at\n"
<< "location 15, s1(15), is: "
<< s1( 0,0 ) << "\n\n";

// test copy constructor
String *s4Ptr = new String( s1 );
cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";

// test assignment (=) operator with self-assignment
cout << "assigning *s4Ptr to *s4Ptr" << endl;
*s4Ptr = *s4Ptr; // test overloaded assignment 
cout << "*s4Ptr = " << *s4Ptr << endl;

// test destructor
delete s4Ptr;

// test using subscript operator to create a modifiable lvalue 
s1[ 0 ] = 'H';
s1[ 6 ] = 'B';
cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: "
<< s1 << "\n\n";

// test subscript out of range
cout << "Attempt to assign 'd' to s1[300] yields:" << endl;
s1[ 300 ] = 'd'; // ERROR: subscript out of range
return 0;
} // end main 

//this causes error
//ostream& String::operator<<(ostream &out, const String &str)
//while this doesn't
//solved that's because this is a friend member function, not a
//function of String class.
ostream& operator<<(ostream &out, const String &str)
{
  //since we got a reference, shouldn't we derefence it 
  //str -> sPtr?
  //solved: no & is already derefenced
  out << str.sPtr;

  return out;
}

istream& operator>>(istream &in, String & str)
{
  in >> str.sPtr;
  return in;
}

String::String(const char *s)
{
  length = calLength(s);
  //add 1 for null character
  sPtr = new char[length+1];
  for (int i = 0; i < length+1; i++) {
    this->sPtr[i] = s[i];
  }
}

String::String(const String &str)
{
  this->length = str.length;
  sPtr = new char[length+1];
  for (int i = 0; i < length+1; i++) {
    this->sPtr[i] = str.sPtr[i];
  }
}

String::~String()
{
  delete[] sPtr;
  sPtr = NULL;
}

const String& String::operator=(const String& str)
{
  //same as copying
  this->length = str.length;
  char buf[length+1];

  for (int i = 0; i < length+1; i++) {
    buf[i] = str.sPtr[i];
  }
  delete[] sPtr;
  sPtr = new char[length+1];

  for (int i = 0; i < length+1; i++) {
    sPtr[i] = buf[i];
  }

  return *this;
}


const String& String::operator+=(const String &str)
{
  char buffer[length];
  //we don't need a null character just a character buffer, not a string.
  int tmpLen = length;
  this->length += str.length;
  int i;

  //copy string to temporary buffer.
  for (i = 0; i < tmpLen; i++) {
    buffer[i] = sPtr[i];
  }

  //re-allocate sPtr with bigger size.
  delete[] sPtr;
  sPtr = new char[length+1];

  //copy from temp buffer to original.
  for (i = 0; i < tmpLen; i++) {
    sPtr[i] = buffer[i];
  }

  //add str to original string
  for (i = tmpLen; i < length; i++) {
    sPtr[i] = str.sPtr[i-tmpLen];
  }
  sPtr[i] = '\0';
  
  return *this;
}

bool String::operator!() const
{
  bool isEmpty;
  if (this->length==0) {
    isEmpty = true;
  }
  else 
    isEmpty = false;
  
  return isEmpty;
}

bool String::operator==(const String &s) const
{
  bool isEqual = true;
  int i;

  if (this->length != s.length) {
    //if different length, we don't have to look at the contents
    isEqual = false;
  }
  else {
    for (i = 0; i < this->length; i++) {
      //if there is different character
      if(this->sPtr[i] != s.sPtr[i]) {
        isEqual = false;
        break;
      }// endif
    }
  }// endif
  
  return isEqual;
}

bool String::operator<(const String &s) const
{
  bool comesFirst = false;
  int i;

  for (i = 0; i < myMin(this->length,s.length); i++) {
    if(this->sPtr[i] < s.sPtr[i]) {
      comesFirst = true;
      break;
    }// endif
    else if(this->sPtr[i] > s.sPtr[i]) {
      comesFirst = false;
      break;
    }// endif
  }
  //if same till the end, default value(false) will be returned.
  return comesFirst;
}

bool String::operator!=(const String &right) const
{
  return !(*this==right);
}

bool String::operator>(const String &s) const
{
  bool comesLater=false;
  int i;

  for (i = 0; i < myMin(this->length,s.length); i++) {
    if(this->sPtr[i] < s.sPtr[i]) {
      comesLater = false;
      break;
    }// endif
    else if(this->sPtr[i] > s.sPtr[i]) {
      comesLater = true;
      break;
    }// endif
  }
  //if same till the end, default value(false) will be returned.
  return comesLater;
  //vs 
  //easier but slower
  //return (!(*this < right) && !(this == right));
}

// < or == 
bool String::operator<=(const String &right) const
{
  return (*this < right || *this == right);
}

// > or == 
bool String::operator>=(const String &right) const
{
  return (*this > right || *this == right);
}

char& String::operator[](int a)
{
  try {
    if(a < 0 || a > this->length-1)
      throw a;
  }
  catch(int exception) {
    std::cout << "Array Exception: index " <<
      exception << " is out of range." << std::endl;
  }
  
  return (this->sPtr[a]);
}

char String::operator[](int a) const
{
  try {
    if(a < 0 || a > this->length-1)
      throw a;
  }
  catch(int exception) {
    std::cout << "Array Exception: index " <<
      exception << " is out of range." << std::endl;
  }
  
  return (this->sPtr[a]);
}

//return a substring
String String::operator()(int start, int end) const
{
  int i=0;
  String s;
  try {
    if(start < 0 || start > this->length-1)
      throw start;
    else if(end < 0 || end > this->length-1)
      throw end;
  }
  catch(int exception) {
    std::cout << "Array Exception: index " <<
      exception << " is out of range." << std::endl;
  }

  //add 1 for null character
  s.length = (start<=end? end-start+1 : length-start +1);

  delete[] s.sPtr;
  s.sPtr = new char[s.length+1];
  //normal substring
  //this case cares for string(0,0) -> first letter.
  if (start <= end) {
    for (i = 0; i < end - start + 1; i++) {
      s.sPtr[i] = this->sPtr[start+i];
    }
    s.sPtr[i] = '\0';
  }// endif

  else if (end==0) {
    for (i = 0; i < s.length; i++) {
      s.sPtr[i] = this->sPtr[start+i];
    }
    s.sPtr[i] = '\0';
  }

  return s;
}

int String::getLength() const
{
  return this->length;
}


int String::myMin(int a, int b) const
{
  return a>b? b : a;
}


int String::calLength(const char *str)
{
  int cnt=0;

  while (true) {
    if (str[cnt]!='\0') {
      cnt++;
    }
    else 
      break;
  }
  
  return cnt;
}

void String::setString(const char *str)
{
  int len = calLength(str);
  delete[] sPtr;

  sPtr = new char[len + 1];
  for (int i = 0; i < len+1; i++) {
    sPtr[i] = str[i];
  }
  
  return;
}
