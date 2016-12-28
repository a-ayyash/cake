#include <vector>
#include <iostream>
using namespace std;

vector<int> ProductsOfOthers(const vector<int> &vec) {
  vector<int> result(vec.size(), 1);

  //forward iteration
  int total = 1;

  for(int i = 1; i < vec.size(); i++) {
    total *= vec[i-1];
    result[i] = total;
  }

  total = 1;

  for(int i = vec.size() - 2; i >=0; i--) {
    total *= vec[i + 1];
    result[i] *= total;
  }

  return result;
}

int main() {
  vector<int> products = ProductsOfOthers({1, 7, 3, 4});

  for(int i : products) {
    cout << i << " ";
  }

  cout << endl;
  return 0;
}
