// 재채점 하고난 후 틀려서 다시 풀었다. 난이도에 비해서 많은 시간을
// 할애 했지만 그만큼 큰 것을 얻었다. 당시 기법은 잘 모르니까 일단
// 이해도 안하고 반복문 DP를 어느 블로그에서 베껴왔던 것 같은데,
// 재귀 DP로 재설계 하면서 캐시를 활용한 DP 해 역추적하는 방법을
// 제대로 숙지한 것 같다

#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>

int N, M, ans, cache[1005][1005];
std::string s1, s2, char_ans;
std::stack<char> tracker;

int DP(int idx1, int idx2){
    if(idx1 == N || idx2 == M)
        return 0;

    int &ret = cache[idx1][idx2];
    if(ret != -1) return ret;

    ret = 0;

    if(s1[idx1] == s2[idx2])
        ret = std::max(ret, DP(idx1 + 1, idx2 + 1) + 1);
    ret = std::max(ret, DP(idx1 + 1, idx2));
    ret = std::max(ret, DP(idx1, idx2 + 1));
    ret = std::max(ret, DP(idx1 + 1, idx2 + 1));
    
    return ret;
}
bool possible(int r, int c){
    return r < N && c < M;
}
void tracking(int idx1, int idx2){
    if(char_ans.size() == cache[0][0])
        return;
    if(tracker.size() == cache[0][0]){
        std::string tmp = "";

        while(!tracker.empty()){
            tmp += tracker.top();
            tracker.pop();
        }
        char_ans = tmp;
        return;
    }
    if(idx1 == N || idx2 == M)
        return;

    if(s1[idx1] == s2[idx2]){
        tracker.push(s1[idx1]);
        tracking(idx1 + 1, idx2 + 1);
        tracker.pop();
    }

    if(possible(idx1 + 1, idx2) && cache[idx1 + 1][idx2] == cache[idx1][idx2])
        tracking(idx1 + 1, idx2);
    if(possible(idx1, idx2 + 1) && cache[idx1][idx2 + 1] == cache[idx1][idx2])
        tracking(idx1, idx2 + 1);
    if(possible(idx1 + 1, idx2 + 1) && cache[idx1 + 1][idx2 + 1] == cache[idx1][idx2])
        tracking(idx1 + 1, idx2 + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(cache, -1, sizeof(cache));

    std::cin >> s1 >> s2;
    N = s1.size();
    M = s2.size();
    
    ans = DP(0, 0);
    
    std::cout << ans << "\n";
    if(ans){
        tracking(0, 0);
        for(int i = char_ans.size() - 1; i >= 0 ; --i)
            std::cout << char_ans[i];
    }

    return 0;
}


// #include<iostream>
// #include<string>

// int ansr, ansc, ans, cache[1005][1005];
// std::string input1, input2, str_cache[1005][1005];

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     std::cin >> input1 >> input2;
//     for(int i = 0; i < 1005; ++i)
//         str_cache[0][i] = str_cache[i][0] = "";
//     for(int i = 1; i <= input1.size(); ++i){
//         for(int u = 1; u <= input2.size(); ++u){
//             if(input1[i - 1] == input2[u - 1]){
//                 cache[i][u] = cache[i - 1][u - 1] + 1;
//                 str_cache[i][u] = str_cache[i - 1][u - 1];
//                 str_cache[i][u].push_back(input1[i - 1]);
//             }
//             else{
//                 if(cache[i - 1][u] < cache[i][u - 1]){
//                     cache[i][u] = cache[i][u - 1];
//                     str_cache[i][u] = str_cache[i][u - 1];
//                 }
//                 else{
//                     cache[i][u] = cache[i - 1][u];
//                     str_cache[i][u] = str_cache[i - 1][u];
//                 }
//             }
//         }
//     }
//     for(int i = 1; i <= input1.size(); ++i)
//     for(int u = 1; u <= input2.size(); ++u){
//         if(cache[i][u] > ans){
//             ans = cache[i][u];
//             ansr = i; ansc = u;
//         }
//     }
//     std::cout << ans << "\n";
//     std::cout << str_cache[ansr][ansc];
//     return 0;
// }
