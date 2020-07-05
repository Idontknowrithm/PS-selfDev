// normal wrong
// matching 스택에 대한 런타임 문제와
// asdfasdf 패턴에 대해서는 생각함
// asdasdf 패턴에 대한 생각을 못함

// asdasdasdfasdf
// asdasdf          <-- counter tc 생각 못함
#include<iostream>
#include<stack>
#include<vector>

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::string input, blowUp;
    std::cin >> input >> blowUp;
    std::stack<char> boom, temp;
    std::stack<int> matching;
    for(int i = 0; i < input.size(); ++i){
        boom.push(input[i]);
        if(!matching.empty() && input[i] == blowUp[matching.top() + 1]){
            matching.push(matching.top() + 1);
        }
        if(!matching.empty() && matching.top() == blowUp.size() - 1){
            for(int u = 0; u < blowUp.size(); ++u){
                matching.pop();
                boom.pop();
            }
        }
        if(input[i] == blowUp[0] && (matching.empty() || (!matching.empty() && blowUp[matching.top()] != blowUp[0]))){
            matching.push(0);
        }
    }
    while(!boom.empty()){
        temp.push(boom.top());
        boom.pop();
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
