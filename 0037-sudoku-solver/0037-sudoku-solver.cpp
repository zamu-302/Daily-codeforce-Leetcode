class Solution {
public:
    int boxes[9];
    int rows[9];
    int cols[9];
    constexpr bool solve(vector<vector<char>>& board)noexcept{
        for(int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if(board[i][j]=='.'){

                    for(int k=1;k<10;k++){
                        int mask=(1<<k);
                        int b=((i/3)*3+(j/3));
                        if(!(mask&(rows[i]|cols[j]|boxes[b]))){
                            boxes[b]|=mask;
                            rows[i]|=mask;
                            cols[j]|=mask;
                            board[i][j]=char('0'+k);
                            if(solve(board)){
                                return true;
                            }
                            boxes[b]&=~mask;
                            rows[i]&=~mask;
                            cols[j]&=~mask;
                            board[i][j]='.';
                        }

                    }
                    return false;

                }
            }
        }
        return true;
    }
    constexpr void solveSudoku(vector<vector<char>>& board)noexcept {
        
        for(int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]!='.'){
                    int mask=(1<<(board[i][j]-'0'));
                    int b=((i/3)*3+(j/3));
                    rows[i]|=mask;
                    cols[j]|=mask;
                    boxes[b]|=mask;
                        }
                }
                
            }
        solve(board);
        
        

        
    }
};