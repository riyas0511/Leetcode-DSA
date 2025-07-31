class Solution {
private:
    void dfs(int node, vector<int> adjLS[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjLS[node]) {
            if (!vis[it]) {
                dfs(it, adjLS, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLS[n];

        // Convert adjacency matrix to list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);  // Since undirected
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjLS, vis);
            }
        }

        return cnt;
    }
};
