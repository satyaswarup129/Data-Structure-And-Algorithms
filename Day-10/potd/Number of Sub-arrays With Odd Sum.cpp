class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        
        // 'c' will store the final count of subarrays with an odd sum
        int c = 0;
        
        // 'prev' keeps track of the last seen index where the element was odd
        int prev = -1;
        
        // 'MOD' is used to take results modulo (10^9 + 7)
        int MOD = 1e9 + 7;
        
        // 'prev1' stores the previous count of subarrays ending at the previous index with an odd sum
        // 'prev2' stores the previous previous count of subarrays ending at the previous index with an odd sum - for odd no of odd's
        int prev1 = 0, prev2 = 0;
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2) { // If the current element is odd
                int t = i - prev; // Count of subarrays ending at 'i' that contain at least one odd element
                t += prev2; // Include previously counted odd subarrays, as adding an odd element makes them odd
                
                c = (c + t) % MOD; // Update the total count
                
                // Update previous counts for the next iteration
                prev2 = prev1; // Previous odd subarrays now become even when extended
                prev1 = t; // Current odd subarrays count
                
                prev = i; // Update last seen odd index
            } else { // If the current element is even
                c = (c + prev1) % MOD; // Previous odd sum ways(at Index I it has 4 ways to get odd sum now this element is even so this contributes additional 4 ways)
            }
        }
        
        return c; // Return the total count of odd-sum subarrays
    }
};
