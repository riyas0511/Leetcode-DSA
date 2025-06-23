class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int sum;
        for(int i = 0 ; i < n; i++){
            sum = 0;
            for(int j = i; j <n; j++){
                sum += nums[j];
                if(sum == k ){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};