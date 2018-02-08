#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
      string t;
      if (s.size() <= numRows || numRows == 1) {
        return s;
      } else {
        int j = 0;
        // First line
        while (j < s.size()) {
          t.push_back(s.at(j));
          //cout << "line 1: " << s.at(j) << endl;
          j += (numRows - 1) * 2;
        }

        // Middle lines
        for (int i = 1; i < numRows - 1; i++) {
          int j = i;
          int stride = i * 2;//(numRows - 1 - i) * 2;
          while (j < s.size()) {
            //cout << "line " << i + 1 << ": " << s.at(j) << endl;
            t.push_back(s.at(j));
            if (stride == (numRows - 1 - i) * 2)
              stride = i * 2;
            else
              stride = (numRows - 1 - i) * 2;
            j += stride;
          }
        }

        // Last line
        j = (numRows - 1);
        while (j < s.size()) {
          t.push_back(s.at(j));
          //cout << "line " << numRows << ": " << s.at(j) << endl;
          j += (numRows - 1) * 2;
        }
      }              

      return t;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
