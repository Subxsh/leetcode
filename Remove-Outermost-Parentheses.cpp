class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int b=0;
        for(auto i:s){
            if(i=='('&&b++>0){
                res+=i;
            }
            if(i==')'&&--b>0){
                res+=i;
            }
        }
        return res;
    }
};