#include "../stack/stack.h"

class StacksQueue {
  public:
    void enqueue(int key);
    int dequeue();

  private:
    Stack in_stack;
    Stack out_stack;
};
