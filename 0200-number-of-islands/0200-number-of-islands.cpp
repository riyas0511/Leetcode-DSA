class Solution {
    private:
      void bfs(int row, int col, vector<vector<int>> &vis,  vector<vector<char>> &grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
          int n = grid.size();
        int m = grid[0].size();
         

        // Directions: up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int neighr = nrow + drow[i];
                int neighc = ncol + dcol[i];

                if (neighr >= 0 && neighr < n && neighc >= 0 && neighc < m &&
                    grid[neighr][neighc] == '1' && !vis[neighr][neighc]) {
                    vis[neighr][neighc] = 1;
                    q.push({neighr, neighc});
                }
            
        }
      }
      }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int r = 0; r< n ; r++){
            for(int c = 0; c<m; c++){
               if(!vis[r][c] && grid[r][c] == '1'){
                cnt++;
                bfs(r, c, vis , grid);
               }

            }
        }
        return cnt;
    }
};