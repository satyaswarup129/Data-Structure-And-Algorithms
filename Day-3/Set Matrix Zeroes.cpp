class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int cols=matrix[0].size();

        unordered_set<int>setRows;
        unordered_set<int>setCols;

        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    setRows.insert(i);
                    setCols.insert(j);
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                if(setRows.count(i)>0||setCols.count(j)>0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
