#define ll long long
class Solution {
public:
    long long countFairPairs(vector<int>& a, int low, int upp) {
        ll ans=0;
        //sort the vector
        sort(a.begin(),a.end());
        int n=a.size();

        //iterate over each element
        for(int i=0;i<n;i++)
        {
            int l=i+1,h=n-1;

            //f and s will store the last and first index that form 
            //fair pair with current index ,respectively
            int f=-1,s=-1;
            while(l<=h)
            {
                int m=l+h;
                m>>=1;
                if(low<=a[i]+a[m] && a[i]+a[m]<=upp)
                {
                    f=m;
                    l=m+1;
                }
                else if(low>a[i]+a[m])
                {
                    l=m+1;
                }
                else h=m-1;
            }

            l=i+1,h=n-1;
            while(l<=h)
            {
                int m=l+h;
                m>>=1;
                if(low<=a[i]+a[m] && a[i]+a[m]<=upp)
                {
                    s=m;
                    h=m-1;
                }
                else if(low>a[i]+a[m])
                {
                    l=m+1;
                }
                else h=m-1;
            }

            if(f!=-1)
            ans=ans+(f-s+1);

        }

        return ans;
    }
};
