class Solution {
public:
    int findMin(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {  
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[right]) {  
                left = mid + 1;
            } else {  
                right = mid;
            }
        }
        return arr[left];
    }
};
