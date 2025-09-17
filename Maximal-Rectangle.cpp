class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> heights(n,0);
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                heights[j]++;
                else
                    heights[j]=0;
            }
                maxArea=max(maxArea,largestRectangleArea(heights)); 
        }
        return maxArea;
    }
        int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> lfs(n), rfs(n);
        stack<int> s;

        // Left smaller
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

        // Right smaller
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(s.empty())
                rfs[i] = n-1;
            else
                rfs[i] = s.top() - 1;
            s.push(i);
        }

        // Calculate max area
        for(int i = 0; i < n; i++) {
            res = max(res, heights[i] * (rfs[i] - lfs[i] + 1));
        }

        return res;
    }

};