#include<iostream>
#include<cstring>
#include<stack>

int main () {
    char inputStr[101]; int tempI;
    std::stack<char> opeStack;

    scanf("%s", inputStr);
    for(int i = 0; i < strlen(inputStr); ++i){
        if(inputStr[i] >= 'A' &&inputStr[i] <= 'Z'){
            printf("%c", inputStr[i]);
        }
        else if(inputStr[i] == '+'){
            if(opeStack.empty())
                opeStack.push('+');
            else {
                while(!opeStack.empty() && opeStack.top() != '('){
                    printf("%c", opeStack.top());
                    opeStack.pop();
                }
                opeStack.push('+');
            }
        }
        else if(inputStr[i] == '-'){
            if(opeStack.empty())
                opeStack.push('-');
            else {
                while(!opeStack.empty() && opeStack.top() != '('){
                    printf("%c", opeStack.top());
                    opeStack.pop();
                }
                opeStack.push('-');
            }
        }
        else if(inputStr[i] == '*'){
            if(opeStack.empty() || opeStack.top() == '+' || opeStack.top() == '-')
                opeStack.push('*');
            else {
                while(!opeStack.empty() && opeStack.top() != '+' && opeStack.top() != '-' && opeStack.top() != '('){
                    printf("%c", opeStack.top());
                    opeStack.pop();
                }
                opeStack.push('*');
            }
        }
        else if(inputStr[i] == '/'){
            if(opeStack.empty() || opeStack.top() == '+' || opeStack.top() == '-')
                opeStack.push('/');
            else {
                while(!opeStack.empty() && opeStack.top() != '+' && opeStack.top() != '-' && opeStack.top() != '('){
                    printf("%c", opeStack.top());
                    opeStack.pop();
                }
                opeStack.push('/');
            }
        }
        else if(inputStr[i] == '(')
            opeStack.push('(');
        else if(inputStr[i] == ')'){
            while(opeStack.top() != '('){
                printf("%c", opeStack.top());
                opeStack.pop();
            }
            opeStack.pop();
        }   
    }
    while(!opeStack.empty()){
        printf("%c", opeStack.top());
        opeStack.pop();
    }

    return 0;
}
