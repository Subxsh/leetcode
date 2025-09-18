#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int> res;
        int n = a.size();
        deque<int> q;

        for (int i = 0; i < n; i++) {
            while (!q.empty() && a[q.back()] <= a[i]) {
                q.pop_back();
            }
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            q.push_back(i);
            if (i >= k - 1) {
                res.push_back(a[q.front()]);
            }
        }
        return res;
    }
};
