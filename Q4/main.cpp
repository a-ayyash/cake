#include "Meeting.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//the reason we don't look at the `start` variable is that
//the vector is already sorted so as long as there is an overlap 
//we are guaranteed the start is going to be less.
vector<Meeting> mergeMeetings(vector<Meeting> &vec) {
  vector<Meeting> result;

  std::sort(vec.begin(), vec.end());

  //unsigned int start = vec[0].getStartTime();
  unsigned int end = vec[0].getEndTime();
  int range_counter = 0;

  result.push_back(vec[0]);

  for(int i = 1; i < vec.size(); i++) {
    if (vec[i].getStartTime() > end) {
      result.push_back(vec[i]);
      //start = vec[i].getStartTime();
      end = vec[i].getEndTime();
      range_counter++;
    } else {
      //start = min(start, vec[i].getStartTime());
      end = max(end, vec[i].getEndTime());
      //result[range_counter].setStartTime(start);
      result[range_counter].setEndTime(end);
    }
  }

  return result;
}

int main() {
  vector<Meeting> meetings {
    Meeting(1,10),
    Meeting(2,6),
    Meeting(3,5),
    Meeting(7,9)
  };
  vector<Meeting> res = mergeMeetings(meetings);

  for(Meeting m : res) {
    cout << "start = " << m.getStartTime() << ", end = " << m.getEndTime() << endl;
  }

  return 0;
}
