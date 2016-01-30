#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int c = 1, s;
    vector<int> result;
    for (int i = digits.size() - 1; i >= 0; --i) {
      s = digits[i] + c;
      result.push_back(s % 10);
      c = s / 10;
    }
    if (c > 0)
      result.push_back(c);
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  vector<int> digits = {9,9,9,9,9}, result;
  Solution s;
  result = s.plusOne(digits);

  for (auto &e : result)
    cout << e;
  cout << endl;
  return 0;
}
