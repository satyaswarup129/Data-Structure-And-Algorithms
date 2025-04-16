class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int temp, count, storeCount = 0;

        for (int i = 0; i < n; i++) {
            temp = 128; // 0b10000000
            count = 0;

            // Count leading ones in current byte
            while ((data[i] & temp) != 0) {
                count++;
                temp >>= 1;
            }

            if (count > 4) {
                return false;
            } else if (count > 1) {
                if (storeCount != 0) {
                    return false;
                }
                storeCount = count - 1;
            } else if (count == 0) {
                if (storeCount != 0) {
                    return false;
                }
            } else {
                if (storeCount >= 1) {
                    storeCount--;
                } else {
                    return false;
                }
            }
        }

        return storeCount == 0;
    }
};
