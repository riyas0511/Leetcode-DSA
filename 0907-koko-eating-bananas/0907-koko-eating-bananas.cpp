#include <cmath>

class Solution {
public:
      long long totalhrs(const vector<int>& arr, int hourly) {
       long long totalM = 0;  // Use long long to prevent overflow
        for (int i = 0; i < arr.size(); i++) {
         totalM +=   ceil( arr[i] / (double)hourly);
          
      }
       return totalM;
    }


        int maxelem(vector<int>& arr){
            int max1=INT_MIN;
            for(int i=0;i<arr.size();i++){
                max1=max(max1,arr[i]);
            }
            return max1;
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 , high = maxelem(piles);
        while(low<=high){
            int mid = low +(high-low)/2;
            long long totalH = totalhrs(piles,mid);
            if(totalH <= h){
                high= mid-1;
            }else{
                low=mid+1;
            }
        }
          return low;
    }
};