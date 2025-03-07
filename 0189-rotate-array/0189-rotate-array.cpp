class Solution {
public:
//     void rotate(vector<int>& nums, int k) {
//         //BRUTE FORCE 
//           int n = nums.size();
//         if (n == 0) return; 

//         k = k % n; // Ensure k is within valid bounds
//         vector<int> temp(k); // Fix: Use vector instead of a VLA

//         // Step 1: Store last k elements
//         for (int i = 0; i < k; i++) {
//             temp[i] = nums[n - k + i];
//         }

//         // Step 2: Shift the remaining elements to the right
//         for (int i = n - 1; i >= k; i--) {
//             nums[i] = nums[i - k];
//         }

//         // Step 3: Copy stored elements back to the front
//         for (int i = 0; i < k; i++) {
//             nums[i] = temp[i];
//         }
//     }
// };
    
    //oPTIMAL- Reversal Alogorithm
    void Reverse(vector<int>& arr, int start , int end){
        while(start<=end){
            int temp = arr[start];
            arr[start]= arr[end];
            arr[end]= temp;
            start++;
            end--;

        }
    }
   void rotate(vector<int>& nums, int k) {
      int n = nums.size();
    if (n == 0) return;

    k = k % n; // Fix: Handle cases where k > n

    // Step 1: Reverse first part (first k elements)
    Reverse(nums, 0, n - k - 1);  // Fix: Reverse first n-k elements

    // Step 2: Reverse second part (remaining elements)
    Reverse(nums, n - k, n - 1); 

    // Step 3: Reverse the whole array
    Reverse(nums, 0, n - 1);
}

    
  
   
};