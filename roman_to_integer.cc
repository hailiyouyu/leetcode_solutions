class Solution {
public:
  int romanToInt(string s) {
    map<char, int> symbols;
    symbols['I'] = 1;
    symbols['V'] = 5;
    symbols['X'] = 10;
    symbols['L'] = 50;
    symbols['C'] = 100;
    symbols['D'] = 500;
    symbols['M'] = 1000;

    vector<int> bits(s.size());
    for (auto i = 0; i != s.size() - 1; ++i) {
      if (symbols[s[i]] < symbols[s[i+1]])
        bits[i] = -symbols[s[i]];
      else
        bits[i] = symbols[s[i]];
    }
    bits[s.size()-1] = symbols[s[s.size()-1]];

    int sum = 0;
    for (auto i = 0; i != s.size(); ++i)
      sum += bits[i];
    return sum;
  }
};
