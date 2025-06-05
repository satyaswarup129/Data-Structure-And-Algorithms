class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        std::iota(parent.begin(), parent.end(), 0);
        int n = s1.size();

        function<int(int)> findParent = [&](int child) -> int {
            if(parent[child] == child) return child;
            return parent[child] = findParent(parent[child]);
        };

        for (int i=0; i<n; i++){      
            if(s1[i]==s2[i]) continue;
            int parentOfs1 = findParent(s2[i]-'a');
            int parentOfs2 = findParent(s1[i]-'a');
            parent[s2[i]-'a'] = parent[s1[i]-'a'] = 
            parent[parentOfs1] = parent[parentOfs2] = min(parentOfs1,parentOfs2);
        }
        
        string ans;
        for(auto i : baseStr){
            char c = findParent(i-'a') + 'a';
            ans.push_back(c);
        }

        return ans;
    }
};
