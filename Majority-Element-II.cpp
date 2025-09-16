class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int voter1=0,voter2=0,vc1=0,vc2=0;
        for (auto ele:nums){
            if(voter1==ele){
                vc1++;
            }
            else if(voter2==ele){
                vc2++;
            }
            else if(vc1==0){
                voter1=ele;
                vc1++;
            }
            else if(vc2==0){
                voter2=ele;
                vc2++;
            }
            else{
                vc1--;
                vc2--;
            }

        }
        int count1=0,count2=0;
        for(auto ele:nums){
            if(ele==voter1)
                count1++;
            
            else if(ele==voter2)
                count2++;
        }
            vector<int> res;
            if(count1>n/3){
                res.push_back(voter1);
            }
            if(count2>n/3){
                res.push_back(voter2);
            }
            
        
        return res;
    }
};