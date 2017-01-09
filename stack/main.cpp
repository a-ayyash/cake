#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  Stack s;
  s.push(1);
  s.push(155);
  s.push(53);
  s.push(56);
  s.push(57);
  s.push(58);

  s.print();


  cout << "----------------" << endl;
  cout << s.top() << endl;
  cout << "----------------" << endl;
  cout << s.pop() << endl;
  cout << s.top() << endl;
  cout << "----------------" << endl;
  cout << s.pop() << endl;
  cout << s.top() << endl;
  cout << "----------------" << endl;
  cout << s.pop() << endl;
  cout << s.top() << endl;
  return 0;
}
