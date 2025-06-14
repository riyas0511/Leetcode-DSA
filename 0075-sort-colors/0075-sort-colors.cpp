class Solution {
public:
     
    void swap(int &arr1, int &arr2){
        int temp =  arr1;
         arr1 = arr2;
         arr2 = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int mid = 0;
        int right = n - 1;
        while( mid <= right){
            
            if(nums[mid]==0){
                swap(nums[left], nums[mid]);
                left++;
                mid++;

            }
            else if( nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums[right], nums[mid]);
                right--;
            }
        }
    }
};