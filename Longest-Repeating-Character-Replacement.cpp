#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, ans = 0, maxCount = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxCount = max(maxCount, freq[s[right]]);

            // Shrink the window if more than k replacements needed
            while ((right - left + 1) - maxCount > k) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};