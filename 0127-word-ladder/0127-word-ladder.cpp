class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> listcopy(wordList.begin(), wordList.end());
        listcopy.erase(beginWord);
        while(!q.empty()){
            string fw = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(fw==endWord) return steps;
            for(int i =0; i < fw.size(); i++){
                 char orig = fw[i];
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    fw[i] = ch;
                    if(listcopy.find(fw)!=listcopy.end()){
                        listcopy.erase(fw);
                        q.push({fw, steps+1});
                    }
                }
                fw[i] = orig;
            }
        }
        return 0;
    }
};