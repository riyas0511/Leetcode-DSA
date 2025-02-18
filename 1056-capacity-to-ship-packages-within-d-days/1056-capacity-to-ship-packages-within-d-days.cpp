class Solution {
public:
    int minCap(vector<int>& weights,int  min){
        int n = weights.size();
        int sum = 0;
        int days= 1;
        for(int i = 0; i< n; i++){
            if(sum + weights[i] > min){
                days += 1;           //move to the next day
                sum = weights[i];       //load the weight
            }else{
            sum += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i =0; i<weights.size();i++){
            sum += weights[i];
        }
        int low =*max_element(weights.begin(), weights.end()) , high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;
            int totaldays = minCap(weights, mid);
            if(totaldays<=days){
                high= mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};