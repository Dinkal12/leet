class Solution {
public:
    long long bfs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r,c});

        long long sum = grid[r][c];
        grid[r][c] = 0;

        int dr[]={1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int d=0; d<4;d++){
                int nx = x + dr[d], ny = y + dc[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&grid[nx][ny] > 0) {
                    sum += grid[nx][ny];
                    grid[nx][ny] = 0;
                    q.push({nx, ny});                
            }
        }
    }
    return sum;
}
    int countIslands(vector<vector<int>>& grid, int k) {
      int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0 && bfs(grid, i, j) % k == 0) {
                    ans++;
                }
            }
        }

        return ans;  
    }
};