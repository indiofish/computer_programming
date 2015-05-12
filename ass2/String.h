#include <iostream>
#include <cstdlib>
using std::ostream;
using std::istream;

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
  const String & operator+=(const char *);

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
  std::cout << "freed!" << std::endl;
  delete[] sPtr;
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

const String& String::operator+=(const char *str)
{
  char *buffer;
  //we don't need a null character because 
  //it's just a character buffer, not a string.
  buffer = new char[length];
  int tmpLen = length;
  this->length += setLength(str);
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
    sPtr[i] = str[i-tmpLen];
  }
  sPtr[i] = '\0';
  
  delete[] buffer;
  return *this;
}


//TODO improve this.
const String& String::operator+=(const String &str)
{
  char *buffer;
  //we don't need a null character?
  //yes, it's just a character buffer, not a string.
  buffer = new char[length+1];
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
  
  delete[] buffer;
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

//returns a reference
//return type is kinda confusing
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
//String type 이 아니라 const char *를 리턴???????????
String String::operator()(int start, int end) const
{
  int i=0;
  static String s;
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
  int len = (start<=end? end-start+1 : length-start +1);
  //add 1 for null character
  //if you don't set length, cout<<s will only print out 1 char(len is 0)
  s.length = len;

  delete[] s.sPtr;
  s.sPtr = new char[len+1];
  //normal substring
  //this case cares for string(0,0) -> first letter.
  if (start <= end) {
    for (i = 0; i < end - start + 1; i++) {
      s.sPtr[i] = this->sPtr[start+i];
    }
    s.sPtr[i] = '\0';
  }// endif

  else if (end==0) {
    for (i = 0; i < len; i++) {
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
