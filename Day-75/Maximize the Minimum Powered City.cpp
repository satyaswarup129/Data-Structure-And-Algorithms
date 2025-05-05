class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size(); 
        long long lo = 0, hi = 2e10; 
        while (lo < hi) {
            long long mid = lo + (hi-lo+1)/2, prefix = 0; 
			int kk = k; 
			bool ok = true; 
			vector<int> ss = stations; 
            for (int i = 0; i < n+r; ++i) {
                if (i < n) prefix += ss[i]; 
                if (i >= 2*r+1) prefix -= ss[i-2*r-1]; 
                if (i >= r && prefix < mid) {
                    if (kk < mid - prefix) {
						ok = false; 
						break; 
					}						
                    kk -= mid - prefix; 
                    if (i < n) ss[i] += mid - prefix; 
                    prefix = mid; 
                }
            }
            if (ok) lo = mid; 
            else hi = mid-1; 
        }
        return lo; 
    }
};
