// problem: 6. Zigzag Conversion
// author: Stéphane Dorotich
// date: 2023-01-08
// https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <cstring>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) return s;
        size_t length = s.length();
        
        char temp[length+1];
        memset(temp, 0, length+1);
        int prim, sec, index, cur;

        prim = (numRows-1) * 2;
        sec = prim;
        index = 0;

        for (int i = 0; i < numRows; i++) {
            cur = i;
            while (cur < length) {
                temp[index++] = s[cur];
                if (sec != prim && sec != 0 && cur+sec < length)
                    temp[index++] = s[cur+sec];
                cur+=prim;
            }
            sec-=2;
        }

        std::string res = temp;
        return res;
    }
};

void usage_error(const char * progName) {
    std::cout << "Usage:\n\t" << progName << " string numRows" << std::endl;
    exit(0);
}

int main(int argc, const char ** argv) {
    if (argc != 3) usage_error(argv[0]);
    std::string s = argv[1];
    int numRows;
    try {
        numRows = std::stoi(argv[2]);
    } catch (const std::invalid_argument & ex) {
        std::cout << ex.what() << std::endl;
        usage_error(argv[0]);
    } catch (const std::out_of_range & ex) {
        std::cout << ex.what() << std::endl;
        usage_error(argv[0]);
    }

    Solution sol;
    std::string res = sol.convert(s, numRows);

    std::cout << "Res: " << res << std::endl;
}