class Solution {
public:
   vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
  vector<int> res(N);
  vector<vector<int>> g(N);
  for (auto p : paths) {
    g[p[0] - 1].push_back(p[1] - 1);
    g[p[1] - 1].push_back(p[0] - 1);
  }
  for (auto i = 0; i < N; ++i) {
    bool used[5] = {};
    for (auto j : g[i]) used[res[j]] = true;
    for (auto fl = 1; fl <= 4; ++fl) {
      if (!used[fl]) res[i] = fl;
    }
  }
  return res;
}
};
