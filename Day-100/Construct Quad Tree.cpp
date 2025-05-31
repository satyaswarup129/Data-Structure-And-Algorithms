
class Solution {

private:
    Node* ConstructIt(const vector<vector<int>>& grid, const int rs,
                      const int re, const int cs, const int ce) {
        static Node* one =
            new Node(true, true, nullptr, nullptr, nullptr, nullptr);
        static Node* zero =
            new Node(false, true, nullptr, nullptr, nullptr, nullptr);

        const int is_one = grid[rs][cs];
        for (auto r = rs; r <= re; ++r) {
            for (auto c = cs; c <= ce; ++c) {
                if (grid[r][c] ^ is_one) {
                    const int row_mid = (rs + re) >> 1;
                    const int col_mid = (cs + ce) >> 1;

                    return new Node(
                        true, false,
                        r > row_mid
                            ? (is_one ? one : zero)
                            : ConstructIt(grid, rs, row_mid, cs, col_mid),
                        r > row_mid
                            ? (is_one ? one : zero)
                            : ConstructIt(grid, rs, row_mid, 1 + col_mid, ce),
                        ConstructIt(grid, 1 + row_mid, re, cs, col_mid),
                        ConstructIt(grid, 1 + row_mid, re, 1 + col_mid, ce));
                }
            }
        }

        return is_one ? one : zero;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return ConstructIt(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }
};
