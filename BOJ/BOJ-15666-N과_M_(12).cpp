#include<iostream>
#include<algorithm>

int N, M, ptr = 0, input[10], num[10], output[30];

int main () {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", &input[i]);
    std::sort(input, input + N);
    num[0] = input[0];
    for(int i = 1; i < N; ++i)
        if(input[i] != num[ptr])
            num[++ptr] = input[i];
    
    //ptr + M
    for(int i = M + ptr - 1; i >= M; --i)
        output[i] = 1;
    do{
        int temp = 0;
        for(int i = 0; i < ptr + M; ++i)
            (output[i]) ? (++temp) : (printf("%d ", num[temp]));
        puts("");
    }while(std::next_permutation(output, output + ptr + M));

    return 0;
}
