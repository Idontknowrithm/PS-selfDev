// #include<iostream>
// #include<cstring>
// #include<vector>

// int T, N, ans, students[100005], visited[100005], done[100005];

// void grouping(int start){
//     memset(visited, 0, (N + 1) * sizeof(int));
//     std::vector<int> searcher;
//     int next = start;
//     searcher.push_back(next);
//     while(1){
//         next = students[next];
//         if(done[next]){
//             for(int i = 0; i < searcher.size(); ++i)
//                 if(!done[searcher[i]]) done[searcher[i]] = -1;
//             break;
//         }
//         else if(visited[next]){
//             int ptr;
//             for(ptr = 0; ptr < searcher.size(); ++ptr){
//                 if(searcher[ptr] == next)      break;
//                 else if(!done[searcher[ptr]])  done[searcher[ptr]] = -1;
//             }
//             for(; ptr < searcher.size(); ++ptr){
//                 done[searcher[ptr]] = 1;
//             }
//             break;
//         }
//         searcher.push_back(next);
//         visited[next] = 1;
//     }
//     searcher.clear();
// }

// int main() {
//     for(scanf("%d", &T); T > 0; --T){
//         ans = 0;
//         memset(done, 0, (N + 1) * sizeof(int));
//         scanf("%d", &N);
//         for(int i = 1; i <= N; ++i)
//             scanf("%d", &students[i]);

//         for(int i = 1; i <= N; ++i)
//             if(i == students[i]){
//                 visited[i] = 1;
//             }
//         for(int i = 1; i <= N; ++i){
//             if(!done[i]) grouping(i);
//         }
//         for(int i = 1; i <= N; ++i)
//             ans += (done[i] == -1) ? 1 : 0;
//         printf("%d\n", ans);
        
//     }
//     return 0;
// }

// bfs, dfs를 그래프에서만 떠올리는 경향
// 넓게 퍼지면서 탐색해야 한다면 bfs,
// 깊숙히 쭉 들어가야하는 필요성이 있다면 dfs
// 자료구조에 국한하지 말고 알고리즘의 쓰임새에 집중할 필요 

#include<iostream>
#include<vector>
#include<cstring>

int T, N, ans, stud[100005], visited[100005], done[100005];

void grouping(int start){
    int next = stud[start];
    visited[start] = 1;

    if(!visited[next])
        grouping(next);
    else if(!done[next]){
        for(int i = next; i != start; i = stud[i])
            ++ans;
        ++ans;
    }
    done[start] = 1;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        ans = 0;
        memset(done, 0, sizeof(done));
        memset(visited, 0, sizeof(visited));
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            scanf("%d", &stud[i]);
        for(int i = 1; i <= N; ++i)
            if(!visited[i])
                grouping(i);
        printf("%d\n", N - ans);
    }
    return 0;
}
