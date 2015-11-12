class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int a = 1, b = 2, t;
    for (auto i = 3; i <= n; ++i) {
      t = a + b;
      a = b;
      b = t;
    }
    return b;
  }
};
