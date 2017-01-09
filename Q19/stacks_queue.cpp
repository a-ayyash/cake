#include "stacks_queue.h"

void StacksQueue::enqueue(int key) {
  in_stack.push(key);
}

int StacksQueue::dequeue() {
  if(out_stack.size() == 0) {
    while(in_stack.size() != 0) {
      out_stack.push(in_stack.pop());
    }
  }

  return out_stack.pop();
}
