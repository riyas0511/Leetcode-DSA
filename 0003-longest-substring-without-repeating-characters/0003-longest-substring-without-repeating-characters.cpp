// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxlen = 0;
//         unordered_set <int> set;
//         int l = 0;
//         int r = 0;
//         if(s.size() == 0){
//             return 0;
//         }
//         while(r < s.length()){
//             while(l < r && set.find(s[r])!= set.end()){
//                set.erase(s[l]);
//                l++;
//             }
            
//             set.insert(s[r]);
//             r++;
//             maxlen = max(maxlen , r - l);
//         }
//         return maxlen;
//     }
// };

class Solution {
 public:
    int lengthOfLongestSubstring(string s) {
        vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
