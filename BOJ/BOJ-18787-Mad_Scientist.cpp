#include<iostream>

const int MAX = 1005;
int N, block, diff[MAX];
std::string A, B;

int main() {
    std::cin >> N >> A >> B;
    for(int i = 0; i < N; ++i){
        diff[i] = (A[i] != B[i]) ? 1 : 0;
    }
    int cur = diff[0];
    for(int i = 1; i < N; ++i){
        if(cur != diff[i]){
            ++block;
            cur = diff[i];
        }
    }
    block /= 2;
    block += diff[0];
    std::cout << block;
    return 0;
}
