#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int N, destroyed_chain;
std::vector<int> chain;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int tmp; scanf("%d", &tmp);
        chain.push_back(tmp);
    }
    std::sort(chain.begin(), chain.end());
    while(1){
        destroyed_chain += chain[0];
        chain.erase(chain.begin());
        if(destroyed_chain == chain.size() - 1){
            printf("%d", destroyed_chain);
            break;
        }
        else if(destroyed_chain > chain.size() - 1){
            printf("%d", chain.size());
            break;
        }
        else{
            continue;
        }
    }
    return 0;
}
