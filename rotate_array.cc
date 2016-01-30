#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k = (k >= nums.size()) ? k % nums.size() : k;
    reverse(nums.begin(), nums.begin() + nums.size() - k);
    reverse(nums.begin() + nums.size() - k, nums.end());
    reverse(nums.begin(), nums.end());
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  Solution s;
  s.rotate(nums, 10);

  for (auto &e : nums)
    cout << e << " ";
  cout << endl;
  return 0;
}
