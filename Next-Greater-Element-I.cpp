class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> s;
        unordered_map<int,int> m;

        for(int i=0; i<n2; i++) {
            while(!s.empty() && s.top() <= nums2[i]) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        while(!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }

        int n1 = nums1.size();
        for(int i=0; i<n1; i++) {
            nums1[i] = m[nums1[i]];
        }
        return nums1;
    }
};
