#include <vector>

class Stack {
  public:
    int top();
    int pop();
    void push(int key);
    int size();
    void print();

  private:
    std::vector<int> stk;
};
