#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<char> >& grid, int i, int j){
        grid[i][j] = '0';
        int n = grid.size();
        int m = grid[0].size();
        if(i>0 && grid[i-1][j] == '1'){
            DFS(grid, i-1, j);
        }
        if(i<n - 1&& grid[i + 1][j] == '1'){
            DFS(grid, i+1, j);
        }
        if(j > 0 && grid[i][j - 1] == '1'){
            DFS(grid, i, j - 1);
        }
        if(j < m - 1&& grid[i][j+1] == '1'){
            DFS(grid, i, j+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int nums = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i= 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == '1'){
                    nums++;
                    DFS(grid, i, j);
                }
            }
        }
        return nums;
    }
};

int main(){
    vector<vector<char>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    Solution sol;
    int result = sol.numIslands(grid);
    cout << result << endl;
    return 0;
}