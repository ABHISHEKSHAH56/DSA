#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();
        if(n == 0)
            return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++)
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    res ++;
                }
        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){

        stack<pair<int, int>> q;
        q.push(make_pair(x, y));
        visited[x][y] = true;
        while(!q.empty()){
            int curx = q.top().first;
            int cury = q.top().second;
            q.pop();

            for(int i = 0; i < 4; i ++){
                int newX = curx + d[i][0];
                int newY = cury + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1'){
                    q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }

        return;
    }

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};