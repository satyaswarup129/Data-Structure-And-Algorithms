class Solution {
public:
    int getBit(int x, int k) {
        return (x >> k) & 1;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int xorXY = 0;
        for (int num : nums)
            xorXY ^= num;

        int pos = 0;
        while (!getBit(xorXY, pos)) pos++;

        int x = 0;
        for (int num : nums)
            if (getBit(num, pos))
                x ^= num;

        int y = xorXY ^ x;
        return {x, y};
    }
};
