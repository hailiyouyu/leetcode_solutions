#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0)
      return result;
    vector<int> first = {1};
    result.push_back(first);
    for (int i = 1; i < numRows; ++i) {
      vector<int> upper = result[i - 1];
      vector<int> row(i + 1);
      for (int j = 0; j < i + 1; ++j) {
        if (j == 0 || j == i)
          row[j] = 1;
        else
          row[j] = upper[j - 1] + upper[j];
      }
      result.push_back(row);
    }
    return result;
  }
};


int main() {
  Solution s;
  vector<vector<int>> result = s.generate(10);
  for (auto &row : result) {
    cout << "[";
    for (auto &e : row) {
      cout << e << " ";
    }
    cout << "]\n";
  }
  return 0;
}
