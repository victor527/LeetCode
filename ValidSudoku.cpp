class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowTotal = board.size(), colTotal = board[0].size();
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        for(int i = 0; i < rowTotal; i++)
        {
            for(int j = 0; j < colTotal; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
        }
        return true;
    }
};