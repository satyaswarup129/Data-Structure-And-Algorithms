class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        set<int> s;
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        int x1=n-1, x2=0, y1=m-1, y2=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                s.insert(targetGrid[i][j]);
            }
        }
        int sz = s.size();
        for(int i=0; i<sz; i++) {
            int flag = 0;
            for(auto colour: s) {
                if(remove(targetGrid, colour)){
                    flag = colour;
                    break;
                }
            }
            if(flag == 0)
                return false;
            s.erase(flag);
        }
        return true;
    }
    bool remove(vector<vector<int>>& targetGrid, int c) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        int x1=n-1, x2=0, y1=m-1, y2=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(targetGrid[i][j]==c) {
                    x1 = min(i, x1);
                    x2 = max(i, x2);
                    y1 = min(j, y1);
                    y2 = max(j, y2);
                }
            }
        }
        for(int i=x1; i<=x2; i++) {
            for(int j=y1; j<=y2; j++) {
                if(targetGrid[i][j]!=c && targetGrid[i][j]!=0) 
                    return false;
            }
        }
        for(int i=x1; i<=x2; i++) {
            for(int j=y1; j<=y2; j++) {
                targetGrid[i][j]=0;
            }
        }
        return true;
    }
};
