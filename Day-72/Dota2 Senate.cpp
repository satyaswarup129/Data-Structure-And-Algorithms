class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int ignoreR=0,ignoreD=0;
        int totR=0,totD=0;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                if(ignoreR>0) ignoreR--;
                else{
                    q.push(senate[i]);
                    totR++;
                    ignoreD++;
                }
            }
            else{
                if(ignoreD>0) ignoreD--;
                else{
                    q.push(senate[i]);
                    totD++;
                    ignoreR++;
                } 
            }
        }
        while(!q.empty() && totD>0 && totR>0){
            if(q.front()=='R'){
                if(ignoreR>0){
                    ignoreR--;
                    totR--;
                }
                else{
                    ignoreD++;
                    q.push(q.front());
                }
            }
            else{
                if(ignoreD>0){
                    ignoreD--;
                    totD--;
                }
                else{
                    ignoreR++;
                    q.push(q.front());
                }

            }
            q.pop();
        }
        if(totD>0) return "Dire";
        else return "Radiant";
    }
};
