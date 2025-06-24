class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_set <int> set;
        int l = 0;
        int r = 0;
        if(s.size() == 0){
            return 0;
        }
        while(r < s.length()){
            while(l < r && set.find(s[r])!= set.end()){
               set.erase(s[l]);
               l++;
            }
            
            set.insert(s[r]);
            r++;
            maxlen = max(maxlen , r - l);
        }
        return maxlen;
    }
};