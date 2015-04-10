#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef void* SDT;

class Node;

class Stack {
  public:
    Stack() {top = NULL;}
    ~Stack() { while (!is_empty()) pop();}

    void make_empty();
    int is_empty();
    void push (SDT);
    SDT pop();

  private:
    Node *top;
};
