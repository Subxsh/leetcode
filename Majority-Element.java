class Solution {
    public int majorityElement(int[] nums) {
        int voter=nums[0];
        int vc=1;
        for (int i=1;i<nums.length;i++){
            
            
            if(voter==nums[i]){
                vc+=1;
            }
            else{
                vc--;
            }
            if(vc==0){
                voter=nums[i+1];
            }    
        }
        return voter;
    }
}