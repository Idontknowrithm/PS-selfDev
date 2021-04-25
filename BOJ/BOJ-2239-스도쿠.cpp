#include<iostream>

int flag, board[15][15], possible[15][15][10];
int row[15][10], col[15][10], block[5][5][10];

void sudoku_solver(int pos){
    if(flag) return;
    int r = pos / 9, c = pos % 9;
    if(pos == 81){
        flag = 1;
        for(int i = 0; i < 9; ++i){
            for(int u = 0; u < 9; ++u)
                std::cout << board[i][u];
            std::cout << "\n";
        }
        return;
    }
    if(board[r][c]){
        sudoku_solver(pos + 1);
    }
    else{
        int tmp = 0, ans[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int i = 1; i < 10; ++i){
            ans[i] = (block[r / 3][c / 3][i] == 1) ? 0 : ans[i];
            ans[i] = (row[r][i] == 1) ? 0 : ans[i];
            ans[i] = (col[c][i] == 1) ? 0 : ans[i];
        }
        
        for(int i = 1; i < 10; ++i){
            if(ans[i]){
                block[r / 3][c / 3][i] = row[r][i] = col[c][i] = 1;
                board[r][c] = i;
                sudoku_solver(pos + 1);
                block[r / 3][c / 3][i] = row[r][i] = col[c][i] = 0;
                board[r][c] = 0;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string input;
    for(int i = 0; i < 9; ++i){
        std::cin >> input;
        for(int u = 0; u < 9; ++u)
            board[i][u] = input[u] - '0';
    }
    for(int i = 0; i < 3; ++i)
    for(int u = 0; u < 3; ++u){
        for(int r = 0; r < 3; ++r)
        for(int c = 0; c < 3; ++c){
            block[i][u][board[i * 3 + r][u * 3 + c]] = 1;
        }
    }
    for(int i = 0; i < 9; ++i){
        for(int u = 0; u < 9; ++u){
            row[i][board[i][u]] = 1;
            col[i][board[u][i]] = 1;
        }
    }
    
    sudoku_solver(0);
    return 0;
}
