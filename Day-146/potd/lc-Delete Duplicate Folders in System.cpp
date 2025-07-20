class Solution {
public:
    struct Trie {
        map<string, Trie*> child;
        bool del;
        Trie() { del = false; }
    };
    void insert(vector<string>& s, Trie *root) {
        Trie* p = root;
        for (auto c : s) {
            if (p->child.find(c) == p->child.end())
                p->child[c] = new Trie();
            p = p->child[c];
        }
    }
    unordered_map<string, vector<Trie*>> m;
    string dfs(Trie* root, string s) {
        string curr = "";
        int i=0;
        for (auto [val, next] : root->child) {
            curr += dfs(next, val) + "$" + to_string(i) + "$";
            i++;
        }
        if (curr != "") {
            m[curr].push_back(root);
        }
        return s + "$" + curr;
    }
    vector<vector<string>> res;
    void dfs1(Trie* root, vector<string> s) {
        if (root->del)
            return;
        if (s.size() > 0)
            res.push_back(s);     
        for (auto [val, next] : root->child) {
            s.push_back(val);
            dfs1(next, s);
            s.pop_back();
        }
    }
    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie *root = new Trie();
        for (auto v : paths)
            insert(v, root);
        dfs(root, "");
        for (auto& [s, vt] : m) {
            if (vt.size() > 1) {
                for (auto& node : vt)
                    node->del = true;
            }
        }
        dfs1(root, {});
        return res;
    }
};
