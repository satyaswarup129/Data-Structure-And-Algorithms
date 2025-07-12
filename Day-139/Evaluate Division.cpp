class Solution {
    int find(int x, vector<int>& parent, vector<double>& weight) {
        if (parent[x] != x) {
            int orig_parent = parent[x];
            parent[x] = find(parent[x], parent, weight);
            weight[x] *= weight[orig_parent];
        }
        return parent[x];
    }

    void unionSet(int x, int y, double value, vector<int>& parent,
                  vector<int>& size, vector<double>& weight) {
        int rootX = find(x, parent, weight);
        int rootY = find(y, parent, weight);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
                swap(x, y);
                value = 1.0 / value;
            }
            parent[rootY] = rootX;
            weight[rootY] =
                weight[x] / (value * weight[y]); // maintain a / b = value
            size[rootX] += size[rootY];
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int nodenumber = 0;
        unordered_map<string, int> node;

        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (!node.count(a))
                node[a] = nodenumber++;
            if (!node.count(b))
                node[b] = nodenumber++;
        }

        int n = nodenumber;
        vector<int> parent(n);
        vector<int> size(n, 1);
        vector<double> weight(n, 1.0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            int x = node[a];
            int y = node[b];
            unionSet(x, y, val, parent, size, weight);
        }

        vector<double> result;
        for (auto& query : queries) {
            string a = query[0];
            string b = query[1];
            if (!node.count(a) || !node.count(b)) {
                result.push_back(-1.0);
                continue;
            }

            int x = node[a];
            int y = node[b];
            int rootX = find(x, parent, weight);
            int rootY = find(y, parent, weight);

            if (rootX != rootY) {
                result.push_back(-1.0);
            } else {
                result.push_back(weight[x] / weight[y]);
            }
        }

        return result;
    }
};
