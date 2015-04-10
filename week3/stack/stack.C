#include "stack.h"

class Node {
  public:
    SDT data;
    Node *next;
};

void Stack::make_empty()
{
  while (!is_empty()) pop();
  top = NULL;
}

int Stack::is_empty() { return top == NULL; }

void Stack::push(SDT i)
{
  Node *new_node = new Node();

  if (new_node == NULL) {
    cerr << "Error in push: stack is full." << endl;
    exit(EXIT_FAILURE);
  }

  else {
    new_node->data = i;
    new_node->next = top;
    top = new_node;
  }
}

SDT Stack::pop() {
  Node *old_top;
  SDT i;

  if (is_empty() ) {
    cerr << "Error in pop: stack is empty." << endl;
    exit(EXIT_FAILURE);
  }

  old_top = top;
  i = top->data;
  top = top->next;

  delete old_top;
  return i;
}
