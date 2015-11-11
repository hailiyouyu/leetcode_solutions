class solution {
public:
  bool canWinNim(int n) {
    if (n == 0)
      return false;
    if (n <= 3)
      return true;
    return !canWinNim(n-1) || !canWinNim(n-2) || !canWinNim(n-3);
  }
};

class Solution2 {
public:
  bool canWinNim(int n) {
    if (n == 0)
      return false;
    if (n <= 3)
      return true;
    vector<bool> base = {true, true, true}; // 1, 2, 3
    for (auto i = 4; i <= n; ++i) {
      bool t = !base[i-1] || !base[i-2] || !base[i-3];
      base[0] = base[1];
      base[1] = base[2];
      base[2] = t;
    }
    return base[2];
  }
};
