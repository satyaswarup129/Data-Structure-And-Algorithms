class Solution {
public:
    int n;
    vector<int> BFS(vector<int>& edge,int s)
    {
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(s);
        int d=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int u=q.front();
                q.pop();
                dist[u]=d;
                int v=edge[u];
                if(v!=-1 && dist[v]==INT_MAX)
                {
                    q.push(v);
                }
            }
            d++;
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        n=edges.size();
        int res=-1,dist=INT_MAX;
        vector<int>d1=BFS(edges,node1);
        vector<int>d2=BFS(edges,node2);
        for(int i=0;i<n;i++)
        {
            int curr=max(d1[i],d2[i]);
            if(curr<dist)
            {
                dist=curr;
                res=i;
            }
        }
        return res;
    }
};
