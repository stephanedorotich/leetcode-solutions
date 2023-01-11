// problem: 11. Container With Most Water
// author: Stéphane Dorotich
// date: 2023-01-10
// https://leetcode.com/problems/container-with-most-water/

#include <algorithm>
#include <iostream>
#include <vector>

#define DEBUG 1

struct Sol {
    int v[3];
};

class Solution {
private:
#ifdef DEBUG
    int iters = 0;
#endif
    int computeArea(std::vector<int>& height, int l, int r) {
        return std::min(height[l], height[r]) * (r - l);
    }

    int max_height_index(std::vector<int>& height, int a, int b) {
        if (height[a] >= height[b]) return a;
        else return b;
    }

    Sol recursiveMaxArea(std::vector<int>& height, int l, int r) {
#ifdef DEBUG
        if (iters++ > 10) return {};
        std::cout << "<" << iters << "> ==========================\n";
        std::cout << "left:  " << l << std::endl;
        std::cout << "right: " << r << std::endl;
#endif

        // base case, one or two cols
        if (l + 1 >= r) {
            Sol s;
            s.v[0] = l;
            s.v[1] = r;
            s.v[2] = max_height_index(height, l, r);
            return s;
        }
        // split into base cases
        int mid_index = (r + l) / 2;
        // std::cout << "left:  " << l << std::endl;
        // std::cout << "right: " << r << std::endl;
        // return {};
        Sol lsol = recursiveMaxArea(height, l, mid_index);
        Sol rsol = recursiveMaxArea(height, mid_index+1, r);

        int maxArea = 0, maxHeight = 0, tempArea = 0, mh_index, l_index, r_index;
        for (int i = 0; i < 3; i++) {
            if (height[lsol.v[i]] > maxHeight) {
                maxHeight = height[lsol.v[i]];
                mh_index = lsol.v[i];
            }
            for (int j = 0; j < 3; j++) {
                if (height[rsol.v[i]] > maxHeight) {
                    maxHeight = height[rsol.v[i]];
                    mh_index = rsol.v[i];
                }
                tempArea = computeArea(height, lsol.v[i], rsol.v[j]);
                if (tempArea > maxArea) {
                    maxArea = tempArea;
                    l_index = lsol.v[i];
                    r_index = rsol.v[j];
                }
            }
        }

        // Check if lsol is best
        tempArea = computeArea(height, lsol.v[0], lsol.v[1]);
        if (tempArea >= maxArea) {
            maxArea = tempArea;
            l_index = lsol.v[0];
            r_index = lsol.v[1];
        }

        // Check if rsol is best
        tempArea = computeArea(height, rsol.v[0], rsol.v[1]);
        if (tempArea > maxArea) {
            maxArea = tempArea;
            l_index = rsol.v[0];
            r_index = rsol.v[1];
        }

        Sol s;
        s.v[0] = l_index;
        s.v[1] = r_index;
        s.v[2] = mh_index;

#ifdef DEBUG
        std::cout << "Best sol in range [" << l << "," << r << "]:" << std::endl;
        std::cout << "\tl_ind: " << l_index << std::endl;
        std::cout << "\tr_ind: " << r_index << std::endl;
        std::cout << "\tm_ind: " << mh_index << std::endl;
        std::cout << "\tDim:   " << r_index - l_index << "x" << std::min(height[l_index], height[r_index]) << std::endl;
        std::cout << "\tArea:  " << computeArea(height, l_index, r_index) << std::endl;
#endif
        return s;
    }

public:
    int maxArea(std::vector<int>& height) {        
        Sol s = recursiveMaxArea(height, 0, height.size()-1);
        return computeArea(height, s.v[0], s.v[1]);
    }
};

int main(const int argc, const char ** argv) {
    Solution s;
    // std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    // std::vector<int> height = {1,0,0,0,0,0,0,2,2};
    std::vector<int> height = {8,10,14,0,13,10,9,9,11,11};

    int area = s.maxArea(height);   

    std::cout << "Max area is: " << area << std::endl;
}