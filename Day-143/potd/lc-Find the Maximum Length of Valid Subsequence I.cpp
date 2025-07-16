class Solution {
public:
    int maximumLength(vector<int>& a) {
        auto solve = [&](auto&& self ,int i,int f,int f2) -> int { return i>=a.size()?0:self(self,i+1,f2?!(a[i]&1):f,f2)+(f?a[i]&1:!(a[i]&1)); };
        return max({solve(solve,0,0,0),solve(solve,0,1,0),solve(solve,0,0,1),solve(solve,0,1,1)});
    }
};
