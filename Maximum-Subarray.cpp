class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int cs=nums[0];
        for(int i=1;i<nums.size();i++){
            if(cs<0)
                cs=0;
                cs+=nums[i];
                if(cs>max){
                    max=cs;
                }
            
        }
        return max;

    }
};