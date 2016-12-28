#include <vector>
#include <iostream>
using namespace std;


int check(int coin, vector<int> denomenations) {
  if (denomenations.size() == 0) {
    return -1;
  }

  if (coin == 0) {
    return 0;
  }

  vector<int> pipe;
  pipe.push_back(coin);

  int count = 0;

  while(!pipe.empty()) {
    int c = pipe.back();
    pipe.pop_back();

    for(int i : denomenations) {
      if (c % i == 0) {
        count++;
        pipe.push_back(c/i);
      } else {
        pipe.push_back(c%i);
      }
    }
  }

  return count;
}


int main() {
  int count = check(7, {1,4});
  cout << count << endl;
  return 0;
}
