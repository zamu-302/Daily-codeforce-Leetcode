class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> boxes[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                auto val{board[i][j]};
                int box_index=(i/3)*3+(j/3);

                if(rows[i].contains(val) || cols[j].contains(val) || boxes[box_index].contains(val)){
                    return false;
                }
                rows[i].insert(val);
                cols[j].insert(val);
                boxes[box_index].insert(val);
            }
        }
        return true;
    }
};