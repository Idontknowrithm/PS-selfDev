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
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL)
#define test std::cout << "ok"
#define endl std::cout << "\n"

const int MAX = 1000005;
int N, min, arr[MAX], ans, key_char[26];
std::string input, key, cleaned = "";
std::queue<int> que[26];

int main() {
    fastio;
    
    std::cin >> input >> key;
    for(int i = 0; i < key.size(); ++i){
        ++key_char[key[i] - 'a'];
    }
    for(int i = 0; i < input.size(); ++i)
        if(key_char[input[i] - 'a'])
            cleaned += input[i];

    for(int i = 0; i < cleaned.size(); ++i){
        que[cleaned[i] - 'a'].push(i);
    }
    while(1){
        int idx;
        bool no = false;

        if(que[key[0] - 'a'].empty())
            break;
        idx = que[key[0] - 'a'].front();
        que[key[0] - 'a'].pop();
        if(key.size() == 1)
            ++ans;
        else{
            for(int i = 1; i < key.size(); ++i){
                while(!que[key[i] - 'a'].empty() && que[key[i] - 'a'].front() <= idx){
                    que[key[i] - 'a'].pop();
                }
                if(que[key[i] - 'a'].empty()){
                    no = true;
                    break;
                }
                idx = que[key[i] - 'a'].front();
                que[key[i] - 'a'].pop();
                if(i == key.size() - 1)
                    ++ans;
            }
        }
        
        if(no) break;
    }
    printf("%d", ans);

    return 0;
}
