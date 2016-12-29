#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool desc(int a, int b) {
  return a > b;
}

int highest_sum_dynamic(vector<int> &vec, int rank) {
  vector<int> highest(rank);

  for(int i = 0; i < rank; i++) {
    highest[i] = vec[i];
  }

  sort(highest.begin(), highest.end(), desc);

  for(int i = 1; i < rank; i++) {
    highest[i] = highest[i] * highest[i-1];
  }

  for(int i = rank; i < vec.size(); i++) {
    int current = vec[i];


    for(int j = highest.size() - 1; j >= 1; j--) {
      highest[j] = max(highest[j-1] * current, highest[j]);
    }

    highest[0] = max(current, highest[0]);
  }


  return highest[rank-1];
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
  vector<int> v {5,2,4,7,8,3,1,5,11};
  vector<int> v2 {5,2,4,7,8};

  highest_sum(v);
  int c = highest_sum_dynamic(v2, 4);
  cout << c << endl;

  return 0;
}
