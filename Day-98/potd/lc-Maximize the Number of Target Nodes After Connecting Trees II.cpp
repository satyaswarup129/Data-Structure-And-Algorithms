class Solution {
public:
    void dfs(int node, int father, int color, vector<vector<int>>&graph, vector<int>&component, vector<int>&bipartite){
        bipartite[color]++;
        component[node] = color;
        int i, ad;
        for(i = 0; i<graph[node].size(); i++){
            ad = graph[node][i];
            if(ad != father){
                dfs(ad, node, !color, graph, component, bipartite);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int i, sum;
        vector<int>bipartite1(2);
        vector<int>bipartite2(2);
        vector<vector<int>>graph1(edges1.size()+1);
        vector<vector<int>>graph2(edges2.size()+1);
        vector<int>component(max(edges1.size(), edges2.size())+1);
        vector<int>ans(edges1.size()+1);
        for(i = 0; i<edges1.size(); i++){
            graph1[edges1[i][0]].push_back(edges1[i][1]);
            graph1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(i = 0; i<edges2.size(); i++){
            graph2[edges2[i][0]].push_back(edges2[i][1]);
            graph2[edges2[i][1]].push_back(edges2[i][0]);
        }
        dfs(0, -1, 0, graph1, component, bipartite1);
        for(i = 0; i<=edges1.size(); i++){
            ans[i] = bipartite1[component[i]];
        }
        dfs(0, -1, 0, graph2, component, bipartite2);
        sum = max(bipartite2[0], bipartite2[1]);
        for(i = 0; i<=edges1.size(); i++){
            ans[i]+=sum;
        }
        return ans;
    }
};
