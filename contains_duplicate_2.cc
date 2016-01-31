#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    if (nums.size() <= 1) {
      return false;
    }
    map<int, vector<int>> dicts;
    for (int i = 0; i <= nums.size(); ++i) {
      dicts[nums[i]].push_back(i);
    }
    for (auto it = begin(dicts); it != end(dicts); ++it) {
      vector<int> index = it->second;
      if (index.size() > 2) {
        sort(index.begin(), index.end());
        for (int i = 0; i < index.size() - 1; ++i) {
          if (index[i+1] - index[i] <= k)
            return true;
        }
      }
    }
    return false;
  }
};

int main() {
  vector<int> nums = {3, 6, 7, 3, 9, 5, 4, 3, 6, 0, 7};
  int k = 4;
  Solution s;
  cout << s.containsNearbyDuplicate(nums, k) << endl;
  return 0;
}
