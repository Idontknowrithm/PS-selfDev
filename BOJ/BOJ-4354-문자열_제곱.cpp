// 100퍼에서 틀린다

#include<iostream>
#include<cstring>

int pi[1000005];
std::string input;

void failure(){
    int front = 0, back = 1;

    for(int i = 1; i < input.size(); ++i){
        if(input[front] == input[back]){
            pi[back] = pi[back - 1] + 1;
            ++front; ++back;
        }
        else{
            pi[back++] = 0;
            front = 0;
        }
    }
}
int main() {
    while(1){
        memset(pi, 0, sizeof(pi));
        std::cin >> input;
        if(input[0] == '.' && input.size() == 1)
            break;
        failure();
        if(pi[input.size() - 1] % (input.size() - pi[input.size() - 1]))
            std::cout << "1\n";
        else{
            int ans = input.size() / (input.size() - pi[input.size() - 1]);
            std::cout << ans << "\n";
        }   
    }
    return 0;
}
