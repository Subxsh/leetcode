class Solution {
public:
    int LCS(int i,int j,string&t1,string&t2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]) return dp[i][j]= 1+LCS(i-1,j-1,t1,t2,dp);
        else return dp[i][j]= max(LCS(i,j-1,t1,t2,dp),LCS(i-1,j,t1,t2,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.size();
        int n2=t2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return LCS(n1-1,n2-1,t1,t2,dp);
    }
};