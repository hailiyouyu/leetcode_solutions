class Solution {
public:
  int addDigits(int num) {
    if (num < 10)
      return num;
    int sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return addDigits(sum);
  }
};

// 0, 1,  2,  3,  4,  5,  6,  7,  8,  9,
//    10, 11, 12, 13, 14, 15, 16, 17, 18
//    19, 20, 21, 22, 23, 24, 25, 26, 27
class Solution {
public:
  int addDigits(int num) {
    if (num == 0)
      return 0;
    return num % 9 == 0 ? 9 : num % 9;
  }
};
