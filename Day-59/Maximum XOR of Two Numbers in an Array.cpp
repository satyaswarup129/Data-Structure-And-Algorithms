class TrieNode{
    public:
    char ch;
    TrieNode * children[2];
    bool isTerminal;

    TrieNode(char ch){
       this->ch=ch;
       for(int i=0;i<2;i++)
       children[i]=NULL;

       isTerminal=false;
    }


};
class Solution {
public:
string getBitString(int x){
    string s="";
    while(x>0){
        if(x%2==0){
            s.push_back('0');

        }
        else s.push_back('1');
        x/=2;
    }

    while(s.size()<32){
        s.push_back('0');
    }

    reverse(s.begin(),s.end());

    return s;
}
    int findMaximumXOR(vector<int>& nums) {
         

         vector<string> bits;

         for(auto i:nums){
            bits.push_back(getBitString(i));
         }

      

        TrieNode * root=new TrieNode('\0');

        for(auto i:bits){
          TrieNode * crawler=root;

          for(auto j:i){
            if(crawler->children[j-'0']==NULL)
            crawler->children[j-'0']=new TrieNode(j);

            crawler=crawler->children[j-'0'];
          }

          crawler->isTerminal=true;
        }

        int ans=0;

        for(auto i:bits){
            TrieNode * crawler=root;
            int res=0;

            for(auto j:i){
               auto k= (j=='0')?'1':'0';

               if(crawler->children[k-'0']!=NULL){
                crawler=crawler->children[k-'0'];
                res=res*2;
                res+=1;
               }
               else{
                crawler=crawler->children[!(k-'0')];
                res=res*2;
                res+=0;
               }
            }

            ans=max(ans,res);
        }


        return ans; 
    }
};
