class Solution {
public:
    int m_turn=0,c_turn=1,M_win=1,C_win=2,draw=0;
    struct Q{
          int m;
          int c;
          int turn;
          int res;
    };
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
         vector<vector<vector<int>>>child(n,vector<vector<int>>(n,vector<int>(2,0)));
         for(int m=0;m<n;m++)
         {
             for(int c=0;c<n;c++)
             {
                  child[m][c][m_turn]=graph[m].size();  //number of possible next positions for mouse
                  child[m][c][c_turn]=graph[c].size();    //number of possible next positions for cat
                  for(auto &i : graph[c])
                  {
                      if(i==0)
                      {
                          child[m][c][c_turn]--;       // cat will not able to fit inside the hole hence obviously can't risk her life and will not go to the hole
                          break;
                      }   
                  }
             }
         }
        // push all the nodes that will definately win
        queue<Q>q;
        for(int c=0;c<n;c++)
        {
            for(int turn=0;turn<=1;turn++)
            {
                dp[0][c][turn]=M_win;  // see mouse want to the hole he will win this time poor hungry cat
                q.push({0,c,turn,M_win}); 
                if(c)     // if not hole 
                {
                    dp[c][c][turn]=C_win;  // cat caught the mouse yipee !!
                    q.push({c,c,turn,C_win});
                }
            }
        }
        while(!q.empty())
        {
            auto &p=q.front();
            q.pop();
            if(p.m==1 && p.c==2 && p.turn==0)  //we have the result 
                return p.res;
            int pre_turn=1-p.turn;    //previous turn = 1- cur_turn
            for(auto &prev : graph[pre_turn==0?p.m:p.c])
            {
			     // we know the result of cur state let's find the result for prev turn
                  int pre_m=pre_turn==0?prev:p.m;   //prev mouse position 
                  int pre_c=pre_turn==1?prev:p.c;     // prev cat position
                  if(!pre_c) continue;  //cat can't be in the hole
                  if(!dp[pre_m][pre_c][pre_turn])  //don't know who wins in prev turn let's find it out
                  {
                      if((p.res==1 && pre_turn==0) || (p.res==2 && pre_turn==1))  //whoever has prev_turn will wins
                      {
                          dp[pre_m][pre_c][pre_turn]=p.res;
                          q.push({pre_m,pre_c,pre_turn,p.res});
                      }
                      else        //whoever has prev_turn will lose
                      {
                          //this child can't let help us win delete him
                          child[pre_m][pre_c][pre_turn]--;
                          if(!child[pre_m][pre_c][pre_turn])   // no child can help us to win
                          {
                              //whoever has prev turn defeat guaranteed for him/her 
                              int result=pre_turn==0 ? 2 : 1;
                              dp[pre_m][pre_c][pre_turn]=result;   //store the result for prev turn
                              q.push({pre_m,pre_c,pre_turn,result});
                          }
                      }
                  }
            }
        }
        return dp[1][2][0];   // return result
    }
};
