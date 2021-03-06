class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    map<int, size_t> counts;
    for (auto i = 0; i != nums.size(); ++i)
      counts[nums[i]]++;
    for (auto kv : counts)
      if (kv.second > 1)
        return true;
    return false;
  }
};

class Solution2 {
public:
  bool containsDuplicate(vector<int>& nums) {
    return nums.size() > set<int>(nums.begin(), nums.end()).size();
  }
};
