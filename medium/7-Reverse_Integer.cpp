// problem: 7. Reverse Integer
// author: Stéphane Dorotich
// date: 2023-01-09
// https://leetcode.com/problems/reverse-integer/

#include <cmath>
#include <iostream>

class Solution {
private:
    bool overflow(const std::string s, bool isNeg) {
        // 10 indentations!! painful to write, but its faster than the alternative of reversing the first 9 digits and checking that the val is <= 147483647
        std::cout << "Hello?\n";
        if (s[9] - '0' < 2)
            return false;
        if (s[9] - '0' == 2) {
            if (s[8] - '0' < 1)
                return false;
            if (s[8] - '0' == 1) {
                if (s[7] - '0' < 4)
                    return false;
                if (s[7] - '0' == 4) {
                    if (s[6] - '0' < 7)
                        return false;
                    if (s[6] - '0' == 7) {
                        if (s[5] - '0' < 4)
                            return false;
                        if (s[5] - '0' == 4) {
                            if (s[4] - '0' < 8)
                                return false;
                            if (s[4] - '0' == 8) {
                                if (s[3] - '0' < 3)
                                    return false;
                                if (s[3] - '0' == 3) {
                                    if (s[2] - '0' < 6)
                                        return false;
                                    if (s[2] - '0' == 6) {
                                        if (s[1] - '0' < 4)
                                            return false;
                                        if (s[1] - '0' == 4) {
                                            if (s[0] - '0' - isNeg <= 7)
                                                return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }

public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0)
            isNeg = true;

        std::string s = std::to_string(x);
        if (isNeg) s = s.substr(1, s.length()-1);
        if (s.length() == 10 && overflow(s, isNeg)) return 0;

        int res = 0;
        for (uint8_t i = 0; i < s.length(); i++)
            res+=(int) ((int) s[i] - '0') * pow(10, i);
        
        if (isNeg) return -res;
        else return res;
    }
};

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " integer" << std::endl;
    exit(0);
}

int main(const int argc, const char ** argv) {
    if (argc != 2) usage_error(argv[0]);

    int x;
    try {
        x = std::stoi(argv[1]);
    } catch (const std::invalid_argument ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        usage_error(argv[0]);
    } catch (const std::out_of_range ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        usage_error(argv[0]);
    }

    std::cout << "Input: x = " << x << std::endl;

    Solution s;
    int output = s.reverse(x);
    std::cout << "Output: " << output << std::endl;
} 