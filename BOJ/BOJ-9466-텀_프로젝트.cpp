#include<iostream>
#include<cstring>
#include<vector>

int T, N, ans, students[100005], visited[100005], done[100005];

void grouping(int start){
    memset(visited, 0, (N + 1) * sizeof(int));
    std::vector<int> searcher;
    int next = start;
    searcher.push_back(next);
    while(1){
        next = students[next];
        if(done[next]){
            for(int i = 0; i < searcher.size(); ++i)
                if(!done[searcher[i]]) done[searcher[i]] = -1;
            break;
        }
        else if(visited[next]){
            int ptr;
            for(ptr = 0; ptr < searcher.size(); ++ptr){
                if(searcher[ptr] == next)      break;
                else if(!done[searcher[ptr]])  done[searcher[ptr]] = -1;
            }
            for(; ptr < searcher.size(); ++ptr){
                done[searcher[ptr]] = 1;
            }
            break;
        }
        searcher.push_back(next);
        visited[next] = 1;
    }
    searcher.clear();
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        ans = 0;
        memset(done, 0, (N + 1) * sizeof(int));
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            scanf("%d", &students[i]);

        for(int i = 1; i <= N; ++i)
            if(i == students[i]){
                visited[i] = 1;
            }
        for(int i = 1; i <= N; ++i){
            if(!done[i]) grouping(i);
        }
        for(int i = 1; i <= N; ++i)
            ans += (done[i] == -1) ? 1 : 0;
        printf("%d\n", ans);
        
    }
    return 0;
}
