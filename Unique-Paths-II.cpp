class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp, g);
    }

    int solve(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& g) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (g[i][j] == 1) { 
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = solve(i + 1, j, m, n, dp, g) + solve(i, j + 1, m, n, dp, g);
    }
};
