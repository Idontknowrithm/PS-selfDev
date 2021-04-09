// 코너 케이스 제대로 확인 못한 잘못

#include<iostream>
#include<vector>
#include<algorithm>

int N, newP, P, input, rank = 1;
std::vector<int> list;

bool cmp(const int &a, const int &b){
    return a > b;
}
bool redundant(int a){
    int red = 0;
    for(int i = 0; i < list.size(); ++i)
        red += (list[i] == a) ? 1 : 0;
    
    return (red > 1) ? true : false;
}

int main() {
    scanf("%d %d %d", &N, &newP, &P);
    if(N == 0){
        printf("1");
        return 0;
    }
    else{
        for(int i = 0; i < N; ++i){
            scanf("%d", &input);
            list.push_back(input);
        }
    }
    list.push_back(newP);
    std::sort(list.begin(), list.end(), cmp);

    if(list[0] == newP) rank = 1;
    else{
        for(int i = 1; i < list.size(); ++i){
            rank = (list[i] != list[i - 1]) ? i + 1 : input;
            if(list[i] == newP) break;
        }
    }
    if(rank < P){
        printf("%d", (list.size() > P && list[P] == newP) ? -1 : rank);
    }
    else if(rank == P){
        printf("%d", (redundant(newP)) ? -1 : rank);
    }
    else{
        printf("-1");
    }
    return 0;
}
