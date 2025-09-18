class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks=0,currmax=0;
        for(int i=0;i<arr.size();i++){
            currmax=max(currmax,arr[i]);
            if(currmax==i) chunks++;
        }
        return chunks;
    }
};