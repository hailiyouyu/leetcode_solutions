class Solution {
public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};

class Solution2 {
public:
  bool isAnagram(string s, string t) {
    for (auto& c : s)
      c = tolower(c);
    for (auto& c : t)
      c = tolower(c);
    array<int, 26> alphas{0};
    for (auto c : s)
      alphas[c-'a']++;
    for (auto c : t)
      alphas[c-'a']--;
    for (auto i : alphas)
      if (i != 0)
        return false;
    return true;
  }
};
