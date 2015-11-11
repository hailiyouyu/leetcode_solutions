class solution {
public:
  bool canWinNim(int n) {
    if (n == 0)
      return true;
    if (n == 1 || n == 3)
      return true;
    if (n == 2 || n == 4)
      return false;
    return !canWinNim(n-1) || !canWinNim(n-3);
  }
};
