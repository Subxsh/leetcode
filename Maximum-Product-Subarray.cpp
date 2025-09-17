class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mp1 = INT_MIN;
        int cp = 1;
        for (int i = 0; i < nums.size(); i++) {
            cp *= nums[i];
            mp1 = max(cp, mp1);
            if (cp == 0) cp = 1;
        }

        cp = 1;
        int mp2 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            cp *= nums[i];
            mp2 = max(cp, mp2);
            if (cp == 0) cp = 1;
        }

        return max(mp1, mp2);
    }
};
