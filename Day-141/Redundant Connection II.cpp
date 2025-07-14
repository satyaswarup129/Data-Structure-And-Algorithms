class Solution {

    vector<int> parent;
    vector<int> rank;

    int findParent(int node) {

        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    bool unionByRank(int u, int v) 
    {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if(parentU == parentV) return false;

        if(rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        }
        else if(rank[parentV] < rank[parentU]) {
            parent[parentV] = parentU;
        }
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }

        return true;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        parent.resize(n + 1, -1);
        rank.resize(n + 1, 0);

        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }

        vector<int> indegree(n + 1, -1);

        int e1 = -1;
        int e2 = -1;

        for(int i = 0; i < n; i ++)  {

            if(indegree[edges[i][1]] != -1) {
                e1 = i;
                e2 = indegree[edges[i][1]];
            }

            indegree[edges[i][1]] = i;
        }

        for(int i = 0; i < n; i++)
        {
            if(i == e1) {
                continue;
            }

            if(!unionByRank(edges[i][0], edges[i][1])) {

                if(e1 == -1) {
                    return edges[i];
                }
                else {
                    return edges[e2];
                }
            }
        }

        return edges[e1];
    }
};
