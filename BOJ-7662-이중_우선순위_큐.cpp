#include<iostream>
#include<vector>
#include<queue>
#include<utility>

int deleted[1000000];

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, N, inp; char order;
    std::priority_queue<std::pair<int, int>> maxH;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minH;

    std::cin >> T;
    while(T--){
        std::cin >> N;
        for(int i = 0; i < N; ++i)
            deleted[i] = 0;
        for(int i = 0; i < N; ++i){
            std::cin >> order >> inp;
            if(order == 'I'){
                minH.push({inp, i});
                maxH.push({inp, i});
            }
            else if(order == 'D' && inp == 1){
                while(!maxH.empty() && deleted[maxH.top().second]){
                    maxH.pop();
                }
                if(!maxH.empty()){
                    deleted[maxH.top().second] = 1;
                    maxH.pop();
                }
            }
            else if(order == 'D' && inp == -1){
                while(!minH.empty() && deleted[minH.top().second]){
                    minH.pop();
                }
                if(!minH.empty()){
                    deleted[minH.top().second] = 1;
                    minH.pop();
                }
            }
        }

        while(!maxH.empty() && deleted[maxH.top().second])
            maxH.pop();
        while(!minH.empty() && deleted[minH.top().second])
            minH.pop();

        if(maxH.empty() && minH.empty())
            std::cout << "EMPTY\n";
        else 
            std::cout << maxH.top().first << " " << minH.top().first << "\n";

        while(!minH.empty())
            minH.pop();
        while(!maxH.empty())
            maxH.pop();
    }
    return 0;
}
