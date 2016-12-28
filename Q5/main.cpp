#include <vector>
#include <iostream>
using namespace std;


int check_without_recursion(int coin, vector<int> denomenations) {
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
      if (i == 1) {
        count++;
        continue;
      }

      if (c <= i) {
        break;
      }

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

size_t changePossibilitiesBottomUp(int amount, const vector<int>& denominations)
{
    vector<size_t> waysOfDoingNCents(amount + 1); // vector of zeros from 0..amount
    waysOfDoingNCents[0] = 1;

    for (const int coin : denominations) {
      cout << "for coin: " << coin << endl << "\t";
      for(size_t i : waysOfDoingNCents) {
        cout << i << " ";
      }
      cout << endl;
        for (int higherAmount = coin; higherAmount < amount + 1; ++higherAmount) {
            int higherAmountRemainder = higherAmount - coin;
            waysOfDoingNCents[higherAmount] += waysOfDoingNCents[higherAmountRemainder];
            cout << "\th = " << higherAmount << " r = " << higherAmountRemainder << endl << "\t";
            for(size_t i : waysOfDoingNCents) {
              cout << i << " ";
            }
            cout << endl;
        }
    }

    return waysOfDoingNCents[amount];
}


int main() {
  //int count = check_without_recursion(12, {1,2,3,4});
  cout << changePossibilitiesBottomUp(20, {3,5,9}) << endl;
  return 0;
}
