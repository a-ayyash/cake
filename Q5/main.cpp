#include <vector>
#include <iostream>
using namespace std;

vector<int> denomenations;

int check(int coin, int count) {
  if (denomenations.size() == 0) {
    return -1;
  }

  if (coin == 0) {
    return 0;
  }


  for(int i : denomenations) {
    cout << "checkout for coin " << coin << " and i " << i << endl;
    if (coin < i) {
      break;
    }


    if (1 == i) {
      count++;
      cout << "count = " << count << endl;
      continue;
    }

    if (coin == i) {
      continue;
    }

    if (coin % i == 0) {
        count = 1 + check(coin/i, count);
      cout << "count = " << count << endl;
    } else {
      int r = check(coin%i, count);

      if (r > 0) {
        count = 1 + (r-1);
        cout << "r count = " << count << endl;
      }
    }
  }

  return count;
}


int main() {
  denomenations = {12, 4};
  int count = check(7, 0);
  cout << count << endl;
  return 0;
}
