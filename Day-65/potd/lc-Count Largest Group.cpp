class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groupSize(37, 0); // max digit sum for n <= 10^4 is 36 (9+9+9+9)

        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            groupSize[sum]++;
        }

        int maxSize = *max_element(groupSize.begin(), groupSize.end());
        int count = 0;
        for (int size : groupSize) {
            if (size == maxSize) count++;
        }

        return count;
    }

    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
