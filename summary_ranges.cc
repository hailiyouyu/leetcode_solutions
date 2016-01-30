#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> summaryRange(vector<int> &nums) {
    int i = 0, j = 1;
    vector<string> result;
    string s;
    bool isstart = true;
    int start;
    if (nums.empty())
      return result;
    if (nums.size() == 1) {
      result.push_back(to_string(nums[0]));
      return result;
    }
    while(i < nums.size()) {
      if (isstart) {
        start = nums[i];
        s += to_string(nums[i]);
      }

      if (nums[j] == nums[i] + 1) {
        ++i;
        ++j;
        isstart = false;
        continue;
      } else {
        if (nums[i] != start) {
          s += "->";
          s += to_string(nums[i]);
        }
        result.push_back(s);
        s = "";
        i = j;
        ++j;
        isstart = true;
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  Solution s;
  vector<string> result = s.summaryRange(nums);
  for (auto &e : result)
    cout << e << " ";
  cout << "\n";
  return 0;
}
