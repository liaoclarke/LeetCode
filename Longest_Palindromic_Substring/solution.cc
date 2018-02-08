#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      string t(s);
      std::reverse(t.begin(), t.end());  
      string r = findLongestCommonSubstring(s, t);
      return r;
    }
    
    string findLongestCommonSubstring(string s, string t) {
      int longest = 0;
      vector<vector<int>> sublength;
      vector<int> result;

      for (int i = 0; i < s.size(); i++) {
        sublength.emplace_back(t.size());
        for (int j = 0; j < t.size(); j++) {
          if (s.at(i) == t.at(j)) {
            if (i == 0 || j == 0) {
              sublength.at(i).at(j) = 1;
            } else {
              sublength.at(i).at(j) = sublength.at(i - 1).at(j - 1) + 1;
            }

            if (sublength.at(i).at(j) > longest && i - sublength.at(i).at(j) + 1 == t.size() - 1 - j) {
              longest = sublength.at(i).at(j);
              result.clear();
              result.push_back(i);
            } else if (longest > 0 && sublength.at(i).at(j) == longest && i - longest + 1 == t.size() - 1 - j) {
              result.push_back(i);
            }
          } else {
            sublength.at(i).at(j) = 0;
          }
        }
      }

      return s.substr(result.at(0) - longest + 1, longest);
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

int main() {
    //string line;
    //while (getline(cin, line)) {
        //string s = stringToString(line);
        //string s = "esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq";
        string s = "babad";
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    //}
    return 0;
}
