#include<iostream>

int N, board[25][25], tmp[25][25];

void up(){
    int combined[25][25] = {0,};
    for(int i = 0; i < N; ++i){
        int start = 0, end = 0;
        while(start < N){
            
        }
    }
}
void down(){

}
void left(){

}
void right(){

}
void mover(int a, int b, int c, int d, int e){
    switch(a){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(b){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(c){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(d){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(e){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
}
int matrix_max(){
    int max = -1;
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        max = (max < tmp[i][u]) ? tmp[i][u] : max;
    return max;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &board[i][u]);
    for(int a = 0; a < 4; ++a)
    for(int b = 0; b < 4; ++b)
    for(int c = 0; c < 4; ++c)
    for(int d = 0; d < 4; ++d)
    for(int e = 0; e < 4; ++e){
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            tmp[i][u] = board[i][u];
        mover(a, b, c, d, e);
    }
    printf("%d", matrix_max());
    return 0;
}
