#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

int N, M, sector_num = 2, board[1005][1005], sector_size[1000005];

void division(int R, int C){

}

int main() {
    char c;
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%c", &c);
            board[i][u] = (int)(c - '0');
        }
        getchar();    
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(!board[i][u])
            division(i, u);
        
    return 0;
}
