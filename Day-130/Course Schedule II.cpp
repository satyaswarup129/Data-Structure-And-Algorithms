class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>adj(numCourses);
        vector<int> indeg(numCourses,0);
        for(int i=0;i<prereq.size();i++){
            indeg[prereq[i][1]]++;
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        vector<int>res;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(res.begin(),res.end());
        if(res.size()!= numCourses) return {};

        return res;
    }
};
