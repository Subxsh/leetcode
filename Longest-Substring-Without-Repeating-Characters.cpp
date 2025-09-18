class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;  // stores last index of each character
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right])) {
                // move left pointer to the right of the last occurrence
                left = max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right; // update last index of current char
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
