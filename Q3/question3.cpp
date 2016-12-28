#include <iostream>
#include <vector>
using namespace std;

bool desc(int i, int j) {
  return i > j;
}

void highest_sum(vector<int> &vec) {
  int highest, lowest, highestProduct2, lowestProduct2, highestProduct3;
  highest = max(vec[0], vec[1]);
  lowest = min(vec[0], vec[1]);

  highestProduct2 = vec[0] * vec[1];
  lowestProduct2 = vec[0] * vec[1];

  highestProduct3 = vec[0] * vec[1] * vec[2];

  for(int i = 2; i < vec.size(); i++) {
    int current = vec[i];

    highestProduct3 = max(max(highestProduct3,
          current * highestProduct2),
          current * lowestProduct2);

    highestProduct2 = max(max(highestProduct2,
          current * highest),
          current * lowest);

    lowestProduct2 = min(min(lowestProduct2,
          current * lowest),
          current * highest);

    highest = max(current, highest);
    lowest = min(current, lowest);
  }

  cout << highestProduct3 << endl;
}


int main() {
  //vector<int> v {5,1,4,7,1,2,4,13,5,6};
  //vector<int> v {-10,-12,-2,-14,-1,-22,-3};
  vector<int> v {5,1,4,7,1,2,4,13,5,6,10};

  highest_sum(v);

  return 0;
}
