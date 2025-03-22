class Solution {
public:
    vector<int> parent, edgeCount, componentSize;

    int findRoot(int node) {
        if (parent[node] == -1) return node;
        return findRoot(parent[node]);
    }
    
    // fn. for merging edge nd node cnt
    void unionComponents(int node1, int node2) {
        int root1 = findRoot(node1), root2 = findRoot(node2);
        // Increase edge count for that node
        edgeCount[root1]++;
        if (root1 != root2) {
            // root2 , roo1 merge
            parent[root2] = root1;
            edgeCount[root1] += edgeCount[root2];
            componentSize[root1] += componentSize[root2];
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int completeComponents = 0;
        parent.assign(n, -1);
        edgeCount.assign(n, 0);
        componentSize.assign(n, 1);
        
        // Computing edges for future merge
        for (const auto &edge : edges) {
            unionComponents(edge[0], edge[1]);
        }
        
        // Checking components completion
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) { 
                int nodes = componentSize[i];
                int expectedEdges = nodes * (nodes - 1) / 2;
                if (edgeCount[i] == expectedEdges) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
};
