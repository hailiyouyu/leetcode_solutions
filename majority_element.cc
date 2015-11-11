class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0;
    int m = nums[0];
    for (auto i = 0; i != nums.size(); ++i) {
      if (nums[i] == m)
        ++count;
      else
        --count;
      if (count < 0) {
        m = nums[i];
        count = 0;
      }
    }
    return m;
  }
};
