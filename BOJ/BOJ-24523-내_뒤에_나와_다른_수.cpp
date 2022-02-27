#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cstring>
#include<cmath>
#define pp std::pair<int, int>
#define ppp std::pair<int, std::pair<int, int>>
#define ll long long

const int MAX = 1000005;
int N, min, arr[MAX], ans[MAX];

int main() {
    memset(ans, -1, sizeof(ans));
    scanf("%d", &N);
    scanf("%d", &arr[0]);
    for(int i = 1; i < N; ++i){
        scanf("%d", &arr[i]);
        for(int u = i - 1; u >= 0; --u){
            if(ans[u] != -1)
                break;
            if(arr[u] == arr[i])
                break;
            if(arr[u] != arr[i])
                ans[u] = i + 1;
        }
    }
    for(int i = 0; i < N; ++i)
        printf("%d ", ans[i]);

    return 0;
}
