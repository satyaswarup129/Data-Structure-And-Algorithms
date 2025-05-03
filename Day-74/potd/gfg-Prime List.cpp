class Solution {
  public:
    vector<int>fun(int n){
       vector<int>ans;
       vector<bool>vis(n+1, true);
       for(int i=2; i*i<=n; i++){
           if(vis[i]){
               for(int j=i*i; j<=n; j+=i){
                   vis[j]=false;
               }
           }
       }
       for(int i=2; i<=n; i++){
           if(vis[i]){
               ans.push_back(i);}
       }
       return ans;
   }
   
    Node *primeList(Node *head) {
        vector<int>primes=fun(10010);
        Node *a=NULL, *b=NULL;
        while(head){
            int x=head->val, y;
            int xx=lower_bound(primes.begin(), primes.end(),x)-primes.begin();
            if(xx>=primes.size()){
                y=primes.back();
            }
            else if(xx==0 or primes[xx]==x ){
                y=primes[xx];
            }
            else{
                int aa=primes[xx-1], bb=primes[xx];
                if((x-aa)==(bb-x)){y=aa;}
                else(x-aa)>(bb-x)?y=bb:y=aa;
            }
            Node *yy=new Node(y);
            if(a==NULL){
                a=yy; b=yy;
            }
            else{
                b->next=yy;
                b=yy;
            }
            head=head->next;
        }
        return a;
    }
};
