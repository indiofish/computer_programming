#include <iostream>
#include <cassert>
using std::ostream;
using std::istream;

class String
{
  friend ostream &operator<<(ostream &,const String &);
  friend istream &operator>>(istream &, String &);

public:
  //default constructor
  String(const char * = "");
  //copy constructor
  String(const String &);
  ~String();
  const String & operator=(const String &);
  const String & operator+=(const String &);

  bool operator!() const;
  bool operator==(const String &) const;
  bool operator<(const String &) const;

  bool operator!=(const String &right) const;
  bool operator>(const String &right) const;
  bool operator<=(const String &right) const;
  bool operator>=(const String &right) const;

  char &operator[](int);
  char operator[](int) const;

  String operator()(int, int = 0) const;
  int getLength() const;

private:
  int length;
  char *sPtr;

  void setString(const char *);
  int myMin(int a, int b) const;
  int setLength(const char *);
  /* data */    
};

String::String(const char *s)
{
  length = setLength(s);

  //TODO:change to dynamic allocation
  //add 1 for null character
  sPtr = new char[length+1];
  //FIXME try avoid using const_cast
  sPtr = const_cast<char*> (s);
  //something
}
String::String(const String &str)
{
  this->length = str.length;
  this->sPtr = str.sPtr;
}

String::~String()
{
  free(sPtr);
  free(&length);
}

const String& String::operator=(const String& str)
{
  //same as copying
  this->length = str.length;
  this->sPtr = str.sPtr;
  
  return *this;
}

//TODO improve this.
//const String& String::operator+=(const String &str)
//{
  //this->length += str.length;

  //sPtr = new char[length+1];
  
  //return *this;
//}

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
    //if different length, we don't have to look at the content
    isEqual = false;
  }
  else {
    for (i = 0; i < this->length; i++) {
      //if there is different character
      if(this->sPtr[i] != s.sPtr[i]) {
        isEqual = false;
        break;
      }
    }
  }
  
  return isEqual;
}

bool String::operator<(const String &s) const
{
  bool comesFirst;
  int i;

  for (i = 0; i < myMin(this->length,s.length); i++) {
    if(this->sPtr[i] < s.sPtr[i]) {
      comesFirst = true;
      break;
    }
    if(this->sPtr[i] > s.sPtr[i]) {
      comesFirst = false;
      break;
    }
  }
  return comesFirst;
}

bool String::operator!=(const String &right) const
{
  bool isDiff = false;
  int i;

  if (this->length != right.length) {
    //if different length, we don't have to look at the content
    isDiff = true;
  }
  else {
    for (i = 0; i < this->length; i++) {
      //if there is different character
      if(this->sPtr[i] != right.sPtr[i]) {
        isDiff = true;
        break;
      }
    }
  }

  return isDiff;
}

bool String::operator>(const String &s) const
{
  bool comesLater;
  int i;

  for (i = 0; i < myMin(this->length,s.length); i++) {
    if(this->sPtr[i] < s.sPtr[i]) {
      comesLater = false;
      break;
    }
    if(this->sPtr[i] > s.sPtr[i]) {
      comesLater = true;
      break;
    }
  }
}

//bool String::operator<=(const String &s) const
//{
  //bool comesFirstorEq;
  //int i;

  //for (i = 0; i < myMin(this->length,s.length); i++) {
    //if(this->sPtr[i] < s.sPtr[i]) {
      //comesFirstorEq = false;
      //break;
    //}
    //if(this->sPtr[i] > s.sPtr[i]) {
      //comesFirstorEq = true;
      //break;
    //}
  //}
//}

//returns a reference
char& String::operator[](int a)
{
  return this->sPtr[a];
}

//return a substring
String String::operator()(int start, int end) const
{
  static char *str;
  assert(start >= 0 && start <= this->length);
  assert(end >= 0 && end <= this->length);
  //add 1 for null character
  str = new char[end-start+1+1];
  int i=0;
  int j=0;

  //normal substring
  if (start <= end) {
    for (i = 0; i < end - start + 1; i++) {
      str[i] = this->sPtr[start+i];
    }
  }
  //reversed substring
  if (start > end) {
    for (i = end; i > start - 1; i--) {
      str[j++] = this->sPtr[i];
    }
  }
  return str;
}

int String::getLength() const
{
  return this->length;
}


int String::myMin(int a, int b) const
{
  return a>b? b : a;
}


int String::setLength(const char *str) 
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

