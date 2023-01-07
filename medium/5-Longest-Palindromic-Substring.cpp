// problem: 5-Longest-Palindromic-Substring
// author: Stéphane Dorotich
// date: 2023-01-07

#include <iostream>

class Solution {
private:
    bool isPalindrome(std::string & s, uint16_t i, uint16_t j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    std::string longestPalindrome(std::string s) {
        uint16_t max_len = 1, pos = 0;
        for (uint16_t i = 0; i < s.length(); i++) {
            for (uint16_t j = i+max_len; j < s.length(); j++) {
                if (s[j] == s[i] && isPalindrome(s, i, j)) {
                    pos = i;
                    max_len = j-i+1;
                    std::cout << "Pal: " << s.substr(pos, max_len) << std::endl;
                }
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
    // if (argc != 2) usage_error(argv[0]);

    Solution s;
    std::string input = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    std::string res = s.longestPalindrome(input);
    std::cout << "Longest Palindromic Substring: " << res << std::endl;
    return 0;
}