class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<std::array<bool,9>,9> rows{}; 
        std::array<std::array<bool,9>,9> cols{};  
        std::array<std::array<bool,9>,9> boxes{};         
        

        int boardIdx;    
        for(int i=0;i<9;i++){
            for(int j=0; j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                boardIdx=((i/3)*3)+(j/3);
                int num=board[i][j]-'1';
                if(rows[i][num] || cols[j][num] || boxes[boardIdx][num]){
                    return false;
                }
                rows[i][num]=true;
                cols[j][num]=true;
                boxes[boardIdx][num]=true;
                


            }
        }
        return true;

    }
};