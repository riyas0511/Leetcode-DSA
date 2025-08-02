class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n , vector<int>(m, 0));
        vector<vector<int>> vis(n , vector<int>(m,0));
        queue<pair<pair<int, int> , int>> q; 
       
        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 0){
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                    q.push({{i,j},0});
                }
                else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[r][c] = steps;
            int delrow[] = { 1, 0, -1, 0};
            int delcol[] = { 0, 1, 0, -1};
            for(int k = 0 ; k< 4; k++){
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol}, steps+1});
                  
                }
            }
        }
        return dis;
    }
};