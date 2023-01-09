// problem: 5-Longest-Palindromic-Substring
// author: Stéphane Dorotich
// date: 2023-01-07

#include <iostream>

class Solution {
private:
    bool isPalindrome(const std::string & s, uint16_t i, uint16_t j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void expandPalindrome(const std::string & s, uint16_t & i, uint16_t & j) {
        while (i > 0 && j < s.length()-1 && s[i-1] == s[j+1]) {
            i--;
            j++;
        }
    }

public:
    std::string longestPalindrome(std::string & s) {
        uint16_t max_len = 1, pos = 0, x, y;
        for (uint16_t i = 0; i < s.length(); i++) {
            if (i+max_len < s.length() && s[i] == s[i+max_len] && isPalindrome(s, i+1, i+max_len-1)) {
                x = i;
                y = i+max_len;
                expandPalindrome(s, x, y);
                pos = x;
                max_len = y-x+1;
                i--;
            } else if (i+max_len+1 < s.length() && s[i] == s[i+max_len+1] && isPalindrome(s, i+1, i+max_len)) {
                x = i;
                y = i+max_len+1;
                expandPalindrome(s, x, y);
                pos = x;
                max_len = y-x+1;
                i--;
            }
        }
        return s.substr(pos, max_len);
    }
};

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " inputString" << std::endl;
    exit(0);
}

int main(int argc, char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    std::string input = argv[1];
    Solution s;
    std::string res = s.longestPalindrome(input);
    std::cout << "Longest Palindromic Substring: " << res << std::endl;
    return 0;
}