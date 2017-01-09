#include "stack.h"
#include <limits>
#include <iostream>
using namespace std;

int Stack::top() {
  if(stk.size() > 0) {
    return stk.back();
  } else {
    return std::numeric_limits<int>::min();
  }
}

int Stack::pop() {
  int key = std::numeric_limits<int>::min();

  if(stk.size() > 0) {
    key = stk.back();
    stk.pop_back();
  }

  return key;
}

void Stack::push(int key) {
  stk.push_back(key);
}

int Stack::size() {
  return stk.size();
}

void Stack::print() {
  for(auto temp = stk.end() - 1; temp >= stk.begin(); temp--) {
    cout << *temp << endl;
  }
}
