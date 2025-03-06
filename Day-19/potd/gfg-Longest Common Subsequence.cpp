class Solution {
  public:
    int lcs(string &s1, string &s2) 
    {
        int l1= s1.size();
        int l2= s2.size();
        int arr[l1+1][l2+1];
        for(int i=0; i<l1+1; i++)
        {
            for(int j =0; j<l2+1; j++)
            {
                if(i==0||j==0)
                {
                    arr[i][j]=0;
                }
                else
                {
                    if(s1[i-1]!=s2[j-1])
                    {
                        arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                    }
                    else
                    {
                        arr[i][j] = arr[i-1][j-1]+1;
                    }
                    
                }
            }
        }
        return arr[l1][l2];
    }
};
