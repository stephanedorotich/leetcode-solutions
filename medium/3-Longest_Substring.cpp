// author: Stéphane Dorotich
// date: 2023-01-06

#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
	int lengthOfLongestSubstring (std::string s) {
		std::vector<uint16_t> chars(256, USHRT_MAX);
		uint16_t i = 0, pos = 0, len, max_len = 0;

		while (i < s.length()) {
			// Check for duplicated characters
			if (chars[s[i]] != USHRT_MAX) {
				// Check for new max length
				len = i - pos;
				if (len > max_len) max_len = len;

				// Reset chars appearing before duplicate
				pos = chars[s[i]];
				for (uint16_t & loc : chars)
					if (loc <= pos)
						loc = USHRT_MAX;
			
				// Update start position of substring to one position after the duplicate character
				pos++;
			}
			chars[s[i]] = i;
			i++;
		}

		// Check len substring at end of string s
		len = i - pos;
		if (len > max_len) max_len = len;
		
		return max_len;
	}
};

int main(int argc, char ** argv) {
	
	Solution s;
	// s.lengthOfLongestSubstring("dvdf");
	std::cout << s.lengthOfLongestSubstring("dvdf") << std::endl;
}
