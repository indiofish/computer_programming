#include <iostream>
#include <cassert>
#include <cstdlib>
using std::ostream;
using std::istream;
using std::free;

class String
{
  friend ostream &operator<<(ostream &, const String &);
  friend istream &operator>>(istream &, String &);

public:
  //default&conversion constructor
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

  //by setting second parameter default to zero, 
  //providing only one parameter means end of string.
  //String operator()(int, int = 0) const;
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

String::String(const char *s)
{
  length = setLength(s);

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
  //why error?
  //free(sPtr);
  //free(&length);
}

const String& String::operator=(const String& str)
{
  //same as copying
  this->length = str.length;
  this->sPtr = str.sPtr;
  
  return *this;
}


//TODO improve this.
const String& String::operator+=(const String &str)
{
  char *buffer;
  //we don't need a null character?
  //yes, it's just a character buffer, not a string.
  buffer = new char[length];
  int tmpLen = length;
  this->length += str.length;
  int i;

  //copy string to temporary buffer.
  for (i = 0; i < tmpLen; i++) {
    buffer[i] = sPtr[i];
  }

  //only if there was realloc!!
  //re-allocate sPtr with bigger size.
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
    //if different length, we don't have to look at the content
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

//FIXME I return true when two strings are equal
bool String::operator<(const String &s) const
{
  bool comesFirst = true;
  int i;

  for (i = 0; i < myMin(this->length,s.length); i++) {
    if(this->sPtr[i] < s.sPtr[i]) {
      comesFirst = true;
      break;
    }// endif
    if(this->sPtr[i] > s.sPtr[i]) {
      comesFirst = false;
      break;
    }// endif
  }
  return comesFirst;
}

bool String::operator!=(const String &right) const
{
  return !(*this==right);
}

//FIXME I return true when two strings are equal
bool String::operator>(const String &s) const
{
  bool comesLater=true;
  int i;

  for (i = 0; i < myMin(this->length,s.length); i++) {
    if(this->sPtr[i] < s.sPtr[i]) {
      comesLater = false;
      break;
    }// endif
    if(this->sPtr[i] > s.sPtr[i]) {
      comesLater = true;
      break;
    }// endif
  }
  return comesLater;
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

//returns a reference
//return type is kinda confusing
char& String::operator[](int a)
{
  assert(a >= 0 && a <= this->length-1);
  return this->sPtr[a];
}

//return a substring
//FIXME should I delete reversed string function 
//and implement an end to string function?
String String::operator()(int start, int end) const
{
  static char *str;
  assert(start >= 0 && start <= this->length-1);
  assert(end >= 0 && end <= this->length-1);
  //add 1 for null character
  //len is absoulute value of length + 1 for null char.
  int len = (start<=end?  end-start + 1 + 1 : start-end+1+1);
  str = new char[len];
  int i=0;
  int j=0;

  //normal substring
  if (start <= end) {
    for (i = 0; i < end - start + 1; i++) {
      str[i] = this->sPtr[start+i];
    }
    str[i] = '\0';
  }// endif
  //reversed substring
  else if (start > end) {
    for (i = start; i > end - 1; i--) {
      str[j] = this->sPtr[i];
      j++;
    }// endif
    str[j] = '\0';
  }// endif
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
