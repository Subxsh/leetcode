class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double  maxAvg = INT_MIN;
        double avg = 0;
        double sum = 0;
        int i = 0; //start
        int j = 0; //end 
        
        while(j < nums.size()){
            sum = sum + nums[j];
            if(j - i + 1 < k){
                j++;
            }else if (j - i + 1 == k){
                cout<< sum;
                avg = sum/k;
                maxAvg = max(avg,maxAvg);
                // update sum
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return maxAvg;
    }
};