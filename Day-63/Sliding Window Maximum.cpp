#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<double, int>, null_type, less<pair<double, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

vector<double> solve(int n, int k, vector<int>& a) {
    vector<double> answer;
    ordered_multiset omst;
    queue<pair<double, int>> q;
 
    for (int i = 0; i < n; i++) {
        if (q.size() == k) {
            if (k & 1) {
                double a = (*omst.find_by_order(k / 2)).first;
                answer.push_back(a);
            } else {
                double b = ((double)(*omst.find_by_order(k / 2 - 1)).first + (double)(*omst.find_by_order(k / 2)).first) / 2.0;
                answer.push_back(b);
            }
 
            double r = q.front().first;
            q.pop();
 
            omst.erase(omst.find_by_order(omst.order_of_key({r, -1})));
        }
 
        omst.insert({a[i], i});
        q.push({a[i], i});
    }
 
    // last window
    if (k & 1) {
        double a = (*omst.find_by_order(k / 2)).first;
        answer.push_back(a);
    } else {
        double b = ((*omst.find_by_order(k / 2 - 1)).first + (*omst.find_by_order(k / 2)).first) / 2.0;
        answer.push_back(b);
    }

    return answer;
}

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(n, k, nums);
    }
};
