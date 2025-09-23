class Solution {
public:
    string longestPalindrome(string s) {
        int res = 1;           // length of longest palindrome
        int n = s.size();
        int start = 0;         // starting index of longest palindrome
        
        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > res) {
                    start = l;
                    res = r - l + 1;
                }
                l--; 
                r++;
            }
            
            // Even length palindrome
            l = i; 
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > res) {
                    start = l;
                    res = r - l + 1;
                }
                l--; 
                r++;
            }
        }
        return s.substr(start, res);
    }
};
