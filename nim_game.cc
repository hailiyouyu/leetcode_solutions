class solution {
public:
  bool canWinNim(int n) {
    if (n == 1 || n == 3)
      return true;
    if (n == 0 || n == 2 || n == 4)
      return false;
    return !canWinNim(n-1) || !canWinNim(n-3);
  }
};

class Solution2 {
public:
  bool canWinNim(int n) {
    if (n == 1 || n == 3)
      return true;
    if (n == 0 || n == 2)
      return false;
    vector<bool> base = {false, true, false}; // 1, 2, 3
    for (auto i = 4; i <= n; ++i) {
      bool t = !base[i-1] || !base[i-3];
      base[0] = base[1];
      base[1] = base[2];
      base[2] = t;
    }
    return base[2];
  }
};
