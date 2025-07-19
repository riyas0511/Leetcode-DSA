class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        long long sum = 0;
        long long maxsum = 0;
        unordered_map<int , int> freq;

         while( r < nums.size()){
            freq[nums[r]]++;
            sum += nums[r];
            if( r >= k){
              freq[nums[l]]--;
              if (freq[nums[l]] == 0) {
                freq.erase(nums[l]);
              }
              sum -= nums[l];
              l++;
            }

            if(r >= k - 1 && freq.size() == k){
                maxsum = max(maxsum , sum);
            }
            r++;
         }
         return maxsum;
    }
};