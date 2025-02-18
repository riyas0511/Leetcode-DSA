class Solution {
public:

    int divisor(vector<int>& nums,int divi){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/divi);
        }
        return sum;
    }
    int maxelem(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i =0 ; i<n ;i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 , high = maxelem(nums);
        while(low<=high){
        int mid = low + (high-low)/2;
        int sumdiv = divisor(nums,mid);
        if(sumdiv<=threshold){
              high= mid-1;
        }
        else{
           low = mid +1;
        }
        }
        return low;
    }
};