// Partition

class Solution {
public:
  void moveZeros(vector<int>& nums) {
    int i = 0;
    for (auto j = 0; j < nums.size(); ++j) {
      if (nums[j] != 0) { // can't write nums[j] > 0, maybe there are negatives
        using std::swap;
        swap(nums[i], nums[j]);
        ++i;
      }
    }
  }
};
