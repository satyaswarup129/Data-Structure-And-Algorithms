class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        queue<int>q;
        unordered_set<int>st;
        for(auto x:initialBoxes) q.push(x);

        int ans=0;
        while(!q.empty()){
            int box=q.front();
            q.pop();
            if(!status[box]){
                st.insert(box);
                continue;
            }
            ans+=candies[box];
            for(auto x:keys[box]){
                status[x]=1;
                if(st.find(x)!=st.end()) q.push(x),st.erase(x);
            }
            for(auto x:containedBoxes[box]) q.push(x); 
        }

        return ans;
    }
};
