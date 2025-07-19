class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char , int> freq;
        int maxlen = INT_MIN;
        if(s.empty()){
            return 0;
            
        }
        while(r < s.size()){
            
            while (freq[s[r]] > 0) {
            freq[s[l]]--;
            l++;
        }
            freq[s[r]]++;
            maxlen = max(maxlen , r - l + 1);
            r++;
        }
        return maxlen;
    }
};