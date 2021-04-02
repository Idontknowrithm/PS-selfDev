#include<iostream>
#include<cstring>

int N, plus;
char table[1500], ans[1500];

int main() {
    scanf("%s", table);
    N = strlen(table);
    ans[0] = ans[1] = ans[2] = ans[3] = '0';

    for(int i = 4; i < N + 4; ++i)
        ans[i] = table[N - i + 3];
    
    for(int i = 0; i < N; ++i){
        int whole = 0;
        whole += (table[N - i - 1] == '1') ? 1 : 0;
        whole += (ans[i] == '1') ? 1 : 0;
        whole += plus;
        switch(whole){
            case 0:
                plus = 0;
                ans[i] = '0';
                break;
            case 1:
                plus = 0;
                ans[i] = '1';
                break;
            case 2:
                plus = 1;
                ans[i] = '0';
                break;
            case 3:
                plus = 1;
                ans[i] = '1';
                break;
            default:
                break;            
        }
    }
    for(int i = N; i < N + 4; ++i){
        int whole = 0;
        whole += (ans[i] == '1') ? 1 : 0;
        whole += plus;
        switch(whole){
            case 0:
                plus = 0;
                ans[i] = '0';
                break;
            case 1:
                plus = 0;
                ans[i] = '1';
                break;
            case 2:
                plus = 1;
                ans[i] = '0';
                break;
            default:
                break;            
        }
    }
    if(plus){
        ans[N + 4] = '1'; ++N;
    }
    N += 4;
    for(int i = N - 1; i >= 0; --i)
        printf("%c", ans[i]);
    return 0;
}
