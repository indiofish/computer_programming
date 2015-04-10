#include "stack.C"

int main(int argc, const char *argv[])
{
  int i = 3;
  char j = 'S';
  float k = 12.0;

  Stack s;
  s.make_empty();
  s.push(&i);
  s.push(&j);
  s.push(&k);

  std::cout << "POP: " << *(float *)s.pop() << std::endl;
  std::cout << "POP: " << *(char *)s.pop() << std::endl;

  if (s.is_empty())
    std::cout << "The stack is empty" << std::endl;
  else
    std::cout << "The stack is not empty" << std::endl;
  
  std::cout << "POP : " << *(int *)s.pop() << std::endl;

  if (s.is_empty())
    std::cout << "The stack is empty" << std::endl;
  else
    std::cout << "The stack is not empty" << std::endl;
  return 0;
}
