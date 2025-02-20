class Solution {
public:

    int subarray(vector<int>& nums, int elem){
        int cnt=1, subarr=0;
        for(int i = 0;i<nums.size(); i++){
            if(subarr + nums[i]<= elem){
                subarr += nums[i];
            }else{
                cnt++;
                subarr = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low+(high-mid)/2;
            int cntarr= subarray(nums, mid);
            if(cntarr > k){
                low = mid+1;
            }else{
            high = mid-1;
            }
        }
        return low;


    }
};