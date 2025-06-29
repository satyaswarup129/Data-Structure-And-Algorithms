class disjoint{
   
    public:
    vector<int>size;
    vector<int>parent;
    disjoint(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findu(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        parent[u]=findu(parent[u]);
        return parent[u];
    }
    void unions(int u,int v)
    {
        int upar=findu(u);
        int vpar=findu(v);
        if(upar==vpar)
        {
            return ;
        }
        else if(size[upar]<size[vpar])
        {
            parent[upar]=vpar;
            size[vpar]+=size[upar];
        }
        else
        {
            parent[vpar]=upar;
            size[upar]+=size[vpar];
        }
    }
};
class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        disjoint ds(v);
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.unions(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<v;i++)
        {
            if(ds.parent[i]==i)
            {
                count++;
            }
        }
        return count;
    }
};
