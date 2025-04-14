class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 1;
        int high = n;
        while(low < high){
            int mid = low + (high - low)/2;
            int count = 0;
            for(int num : nums){
                if(num <= mid) count++;
            }
            if( count > mid){
                high = mid;
            }
            else {
                low = mid + 1;
            }
        } return low;
    }
};