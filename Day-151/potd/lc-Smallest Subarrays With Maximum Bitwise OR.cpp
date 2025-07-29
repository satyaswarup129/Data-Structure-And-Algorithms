class Solution {
public:

    int binary_search(vector<int>& prev  , vector<vector<int>>& prefix , int s ) {
        int l =  s ; 
        int n = prefix.size() ; 
        int r =  n-1 ; 
        int ans =  -1 ; 
        while(l <= r) {
            int  m = r -  (r-l)/2 ; 
            int valid = 1 ; 
            for(int i = 0 ; i  < 32 ; i++) {
                if((prefix[m][i] -  prev[i]) > 0  &&  (prefix[n-1][i] -  prev[i]) > 0) {
                    continue ; 
                }
                if((prefix[m][i] -  prev[i]) == 0  &&  (prefix[n-1][i] -  prev[i]) == 0){
                    continue  ;
                }
                else {
                    valid = 0 ; 
                    break ; 
                }
            }

            if(!valid) {
                l =  m+ 1; 
            }
            else {
                ans = m ; 
                r = m-1 ; 
            }
        } 

        return ans  ;
    }




    vector<int> smallestSubarrays(vector<int>& a) {
        int n =  a.size() ; 
        int max_or =  0 ; 
        // for(auto i :  a) {
        //     max_or =  max_or|i ; 
        // }

        vector<int> bits(32 , 0 ) ; 
        vector<int> ans(n , n) ; 
        // int xor = 
        vector<vector<int>> prefix(n ) ; 
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j <  32 ; j++) {
                if(a[i]&(1  << j)) {
                    // cout << a[i] << " " << j  << endl ;
                    bits[j]++ ;
                }
            }

            prefix[i] = bits  ; 
        }
        // prefix sum of 32 bit mask 
        // for(int i = 0 ; i <  n ; i++ ) {
        //     for(int j = 0 ; j < 32 ; j++) {
        //         cout << prefix[i][j] << " " ; 
        //     }
        //     cout << endl ;
        // }

        for(int i = 0 ; i <  n ; i++) {
            vector<int> final_state(32 , 0 ) ; 
            if(i == 0) {
                // final_state =  prefix[n-1] ; 
            }
            else {
                for(int j =  0 ; j < 32 ; j++) {
                    final_state[j] =  prefix[i-1][j] ; 
                }
            }

            int ind = binary_search(final_state , prefix , i) ; 
            ans[i] = (ind - i + 1) ;   
        }

        
        return ans  ;


    }
};
