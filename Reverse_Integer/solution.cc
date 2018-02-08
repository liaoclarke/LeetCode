#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
      unsigned int p = x >= 0 ? x : 0 - x;        
      long s = 0l;
      int min_int = std::numeric_limits<int>::min();
      int max_int = std::numeric_limits<int>::max();
      while (p != 0 && p % 10 == 0) { p /= 10; }
      while (p) {
        s *= 10;
        s += p % 10;
        p /= 10;
      }
      s = x > 0 ? s : 0 - s;
      if (s > max_int || s < min_int) {
        return 0;
      } else {
        return s;
      }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
