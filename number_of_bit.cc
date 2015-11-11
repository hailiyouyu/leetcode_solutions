class Solution {
public:
  int hamingWeight(unit32_t n) {
    int sum = 0;
    while (n) {
      ++sum;
      n = n & (n - 1);
    }
    return sum;
  }
};
