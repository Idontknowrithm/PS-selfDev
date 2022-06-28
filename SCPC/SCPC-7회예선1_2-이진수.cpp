// 이진수끼리 and or 하는 느낌으로 봐서 2-SAT 개념 떠올렸으나 예선 2번에
// 적용 시키기에는 무리인 듯해서 예외 처리한 다음 그리디로 긁는 알고리즘
// 생각해낸 것까지는 좋은데 세그폴트 때문에 상당히 심하게 헤멤
// 딱히 이유가 없는 세그폴트 뜰 때는 의미없이 메모리 크기를 늘려볼 것
// 이 문제에서는 N 제한이 5만이길래 MAX를 50005로 지정했는데 안돼서
// 10만으로 늘리니까 그냥 되어버림

#include<iostream>
#include<cstring>

const int MAX = 100000;
int T, N, t, A[MAX], B[MAX];

void two_sat(int idx){
    int val = 0;

    do{
        A[idx] = val;
        val = !val;
        idx += 2 * t;
    }while(idx < N && A[idx] == -1);
}

int main() {
    scanf("%d\n", &T);
    for(int z = 1; z <= T; ++z){
        memset(A, -1, sizeof(A));
        scanf("%d %d\n", &N, &t);
        for(int i = 0; i < N; ++i){
            char c;
            scanf("%c", &c);
            B[i] = c - '0';
        }
        getchar();

        for(int i = 0; i < N - t; ++i){
            if(!B[i]) A[i + t] = 0;
            if(!B[N - i - 1]) A[N - i - t - 1] = 0;
        }
        
        for(int i = 0; i < t; ++i){
            A[i + t] = B[i];
            A[N - i - t - 1] = B[N - i - 1];
        }
        
        for(int i = t; i < N - t; ++i){
            if(B[i] == 1 && A[i - t] == 0)
                A[i + t] = 1;
            if(B[i] == 1 && A[i + t] == 0)
                A[i - t] = 1;
        }
        
        for(int i = 0; i < N; ++i){
            if(A[i] == -1)
                two_sat(i);
        }
        printf("Case #%d\n", z);
        for(int i = 0; i < N; ++i)
            printf("%d", A[i]);
        puts("");
    }
    return 0;
}
