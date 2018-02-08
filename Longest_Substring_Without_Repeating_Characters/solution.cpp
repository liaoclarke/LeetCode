class Solution {
  public:
    /*
     * Time complexity: O(n^3)
     * Space complexity: O(min(n, m)), n is the size of string s, m is the size of the charset/alphabet */
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
      int ans = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (allUnique(s, i, j)) {
            ans = std::max(ans, j - i);
          }
        }
      }

      return ans;
    }

    bool allUnique(string s, int start, int end) {
      for (int i = start; i < end; i++) {
        int k = s.find_first_of(s[i]);
        if (k != i) {
          return false;
        } 
      }

      return true;
    }

    /* Time complexity: O(n)
     * Space complexity: O(min(n, m)) 
     * */
    int lengthOfLongestSubstring(string s) {
      std::unordered_set charset = new std::unordered_set();
      int i = 0;
      int j = 0;
      int n = s.size();
      int ans = 0;

      while (i < n && j < n) {
        if (charset.find(s[j]) == charset.end()) {
          charset.insert(s[j++]);
          ans = std::max(ans, j - i);
        } else {
          charset.erase(s[i++]);
        }
      }

      return ans;
    }

    /* Time complexity: O(n)
     * Space complexity: O(min(n, m)) 
     * */
    int lengthOfLongestSubstring(string s) {
      int ans = 0;

      std::unordered_map charmap = new std::unordered_map();
      for (int j = 0, i = 0; j < n; j++) {
        if (charmap.find(s[j]) != charmap.end()) {
          i = std::max(charmap.at(j), i);
        }
        ans = std::max(ans, j - i + 1);
        charmap.insert(s[j], j + 1);
      }
    }
};
