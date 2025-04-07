class Solution {
public:
    unordered_map<int, int> mp;
    
    int hash(string &word)  {
        int h=0;
        for (char c: word)
            h |= 1<<c-'a';
        return h;
    }
    
    int search(const int h)   {
        if (mp.find(h) == mp.end())
            return 0;
        int gs = mp[h];
        mp.erase(h);
        // all possible delete and add edits
        for (int b=0; b<26; ++b)    {
            int h1;
            if ((h>>b) & 1)     // delete
                h1 = h ^ (1<<b);
            else                // add
                h1 = h | (1<<b);
            auto it = mp.find(h1);
            if (it != mp.end())
                gs += search(h1);
        }
        // for possible 26*26 replacements
        for (int b1=0; b1<26; ++b1) {
            if (((h>>b1) & 1) == 0)
                continue;
            // make this bit 0
            int h1 = h ^ (1<<b1);
            for (int b2=0; b2<26; ++b2) {
                if (b2 != b1 && !((h>>b2)&1))   {
                    int h2 = h1 | (1<<b2);
                    auto it = mp.find(h2);
                    if (it != mp.end())
                        gs += search(h2);
                }
            }
        }
        return gs;
    }
    
    vector<int> groupStrings(vector<string>& words) {
        // bit masking
        int n = words.size(), numg = 0, maxg = 0;
        for (int i=0; i<n; ++i)
            ++mp[hash(words[i])];
        for (int i=0; i<n; ++i) {
            const int h = hash(words[i]);
            int gs = search(h);
            numg += (bool)(gs);
            maxg = max(maxg, gs);
        }
        return {numg, maxg};
    }
};
