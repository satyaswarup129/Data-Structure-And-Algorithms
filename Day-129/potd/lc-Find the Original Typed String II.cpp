class Solution {
public:
    vector<int> fre;
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        if(word.size() < k) return 0;
        if(word.size() == k) return 1;

        for (int i = 0; i < word.size(); ) {
            int count = 1;
            while (i + count < word.size() && word[i] == word[i + count]) {
                count++;
            }
            fre.push_back(count);
            i += count;
        }
        int total = 1;
        for(auto i : fre){
            total = ((long long)total*i)%MOD;
        }
        if (fre.size() >= k) {
            return total;
        }
        vector<int> prev(k,0), curr(k,0), pref(k,0);
        prev[0] = 1;
        for(int i = 0; i < fre.size() ; i++){
            curr.assign(k,0);
            pref = prev;
            for(int j = 1 ; j < pref.size(); j++){
                pref[j] = (pref[j] + pref[j-1])%MOD;
            }
            for(int j = 1; j < k ; j++){
                curr[j] = pref[j-1];
                if(j-fre[i]-1>=0){
                    (curr[j] -= pref[j-fre[i]-1])%=MOD;
                }
            }
            prev = curr;
        }
        int ans = 0;
        for(auto i : prev){
            ans = ( ans + i )%MOD;
        }
        return ((long long)total%MOD - ans%MOD + MOD)%MOD;
    }
};
