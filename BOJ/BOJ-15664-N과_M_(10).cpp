// 한 번 틀리고 사전 순이라는 걸 봤음. 한 번 틀린 후라 쓸모없는 정보를 너무 깊게 생각한 것 같음
// 한 번 틀렸을 때 다른 여러 테스트케이스를 돌려보는 것이 더 유용할 것 같음

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int N, M, valid[10], cache[10], numTable[10], permTable[10];

bool same(){
    for(int i = 0; i < M; ++i){
        if(cache[i] > valid[i]) return true;
        if(cache[i] != valid[i]) return false;
    }
    return true;
}

int main() {
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i)
        std::cin >> numTable[i];
    
    std::sort(numTable, numTable + N);

    for(int i = 0; i < M; ++i)
        permTable[i] = 1;
    
    do{
        int ptr = 0;
        for(int i = 0; i < N; ++i)
            if(permTable[i] == 1)
                valid[ptr++] = numTable[i];
        
        if(same())
            continue;
        
        for(int i = 0; i < M; ++i){
            cache[i] = valid[i];
            std::cout << valid[i] << " ";
        }
        std::cout << "\n";
    }while(std::prev_permutation(permTable, permTable + N));

    return 0;
}
