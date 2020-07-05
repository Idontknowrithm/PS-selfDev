// 처리해야하는 예외가 너무 많은 알고리즘이라면
// 다른 알고리즘을 찾아보는 것이 더 빠를 것 같다...

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::string input, blowUp, boom;
    std::stack<char> ans, temp;
    std::cin >> input >> blowUp;
    for(int i = 0; i < input.size(); ++i){
        ans.push(input[i]);
        if(ans.top() == blowUp[blowUp.size() - 1] && ans.size() >= blowUp.size()){
            boom = "";
            for(int u = 0; u < blowUp.size(); ++u){
                boom += ans.top();
                ans.pop();
            }
            std::reverse(boom.begin(), boom.end());
            if(boom != blowUp){
                for(int u = 0; u < boom.size(); ++u)
                    ans.push(boom[u]);
            }
        }
    }
    while(!ans.empty()){
        temp.push(ans.top());
        ans.pop();
    }
    if(temp.empty()){
        std::cout << "FRULA";
        return 0;
    }
    while(!temp.empty()){
        std::cout << temp.top();
        temp.pop();
    }
    
    return 0;
}
