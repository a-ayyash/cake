#include <vector>
#include <iostream>
using namespace std;

vector<int> mergeVectors(vector<int> vec1, vector<int> vec2) {
  vector<int> merged;
  int i = 0;

  while(vec1.size() > 0 && vec2.size() > 0) {
    if(vec1[0] < vec2[0]) {
      merged.push_back(vec1[0]);
      vec1.erase(vec1.begin());
    } else if(vec2[0] < vec1[0]){
      merged.push_back(vec2[0]);
      vec2.erase(vec2.begin());
    } else {
      merged.push_back(vec1[0]);
      vec1.erase(vec1.begin());
      vec2.erase(vec2.begin());
    }
  }

  if(vec1.size() > 0) {
    for(int i : vec1) {
      merged.push_back(i);
    }
  }

  if(vec2.size() > 0) {
    for(int i : vec2) {
      merged.push_back(i);
    }
  }
  return merged;
}

void PrintVector(vector<int> vec) {
  cout << "[";
  for(size_t i = 0; i < vec.size(); ++i) {
      if (i > 0) {
          cout << ", ";
      }
      cout << vec[i];
  }
  cout << "]" << endl;
}

int main(){
  const vector<int> myVector {3, 4, 6, 10, 11, 15, 50};
  const vector<int> alicesVector {1, 5, 8, 12, 14, 19, 20, 21, 23, 24};

  vector<int> mergedVector = mergeVectors(myVector, alicesVector);
  PrintVector(mergedVector);
  PrintVector(myVector);
  return 0;
}
