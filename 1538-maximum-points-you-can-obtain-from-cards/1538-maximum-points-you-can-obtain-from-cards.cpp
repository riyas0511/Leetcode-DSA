class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rsum = 0;
        int lsum = 0;
        int maxsum =0;
         for(int i = 0; i < k ;i++){
          lsum = lsum + cardPoints[i];
          maxsum = lsum;
       }
        int rInd = n-1;
       for(int j = k-1; j >=0 ; j-- ){
        lsum = lsum - cardPoints[j];
        rsum = rsum + cardPoints[rInd];
         rInd = rInd - 1;
        maxsum = max(maxsum, lsum +rsum);
       
       }
       return maxsum;
    }
};