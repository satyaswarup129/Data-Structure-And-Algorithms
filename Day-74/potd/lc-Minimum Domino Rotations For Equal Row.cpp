class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a=tops[0],b=bottoms[0],move=0,c=0,ans=INT_MAX,n=tops.size();
        for(int i=0;i<n;i++){
            if(a!=tops[i]&&a!=bottoms[i]){
                move=INT_MAX;
                break;
            }
            if(a!=tops[i]&&a==bottoms[i])move++;
        }
        ans=min(ans,move);
        move=0;
        for(int i=0;i<n;i++){
            if(b!=tops[i]&&b!=bottoms[i]){
                move=INT_MAX;
                break;
            }
            if(b!=tops[i]&&b==bottoms[i])move++;
        }
        ans=min(ans,move);
        move=0;
        for(int i=0;i<n;i++){
            if(b!=tops[i]&&b!=bottoms[i]){
                move=INT_MAX;break;
            }
            if(b==tops[i]&&b!=bottoms[i])move++;
        }
        ans=min(ans,move);
        move=0;
        for(int i=0;i<n;i++){
            if(a!=tops[i]&&a!=bottoms[i]){
                move=INT_MAX;break;
            }
            if(a==tops[i]&&a!=bottoms[i])move++;
        }
        ans=min(ans,move);
        return ans==INT_MAX ? -1:ans;
    }
};
