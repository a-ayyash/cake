#include "stacks_queue.h"
#include <iostream>
using namespace std;

int main() {
  StacksQueue sq;
  sq.enqueue(10);
  sq.enqueue(11);
  sq.enqueue(12);
  sq.enqueue(13);
  sq.enqueue(14);
  sq.enqueue(15);

  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;

  sq.enqueue(50);
  sq.enqueue(55);
  sq.enqueue(64);
  sq.enqueue(65);

  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;
  cout << sq.dequeue() << endl;

  return 0;
}
