class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea, maximalSquareInHistogram(heights));
        }
        return maxArea;
    }

    int maximalSquareInHistogram(vector<int>& heights) {
        int n = heights.size();
        vector<int> lfs(n), rfs(n);
        stack<int> s;

        // left boundaries
        for(int i = 0; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                lfs[i] = 0;
            else
                lfs[i] = s.top() + 1;
            s.push(i);
        }

        while(!s.empty()) s.pop();

        // right boundaries
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                rfs[i] = n-1;
            else
                rfs[i] = s.top() - 1;
            s.push(i);
        }

        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            int width = rfs[i] - lfs[i] + 1;
            int height = heights[i];
            int side = min(width, height);
            maxSide = max(maxSide, side);
        }

        return maxSide * maxSide;
    }
};
