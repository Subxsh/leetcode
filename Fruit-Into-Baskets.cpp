#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;  
        int l = 0, res = 0;       
        int n = fruits.size();
        
        for (int r = 0; r < n; r++) {
            m[fruits[r]]++;  
            while (m.size() > 2) {
                m[fruits[l]]--;
                if (m[fruits[l]] == 0) {
                    m.erase(fruits[l]);
                }
                l++;
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};
