class Solution {
public:
bool isSafe(vector<string> &board, int rows,int col,int n){
    for(int j=0;j<n;j++){
        if(board[rows][j]=='Q'){
            return false;
        }

    }
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=rows,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=rows,j=col;i>=0 &&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void nqueens( vector<string> &board,int rows, int n,vector<vector<string>> &ans){
if(rows==n){
    ans.push_back({board});
    return;
}

    for(int j=0;j<n;j++){
        if(isSafe(board, rows, j, n)){
            board[rows][j]='Q';
            nqueens(board, rows+1,n,ans);
            board[rows][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        nqueens(board,0,n, ans);
        return ans;
    }
};
