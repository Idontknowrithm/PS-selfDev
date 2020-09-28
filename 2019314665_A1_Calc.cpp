#include<iostream>
#include<cstring>
#include<stack>

int main (int argc, char* argv[]) {
    char inputStr[101]; int tempI;
    double tempD, tempD2;
    std::stack<double> numStack;
    std::stack<char> opeStack;
    FILE* fileR, * fileW;

    fileR = fopen(argv[1], "r");
    fileW = fopen(argv[2], "w");

    if(fscanf(fileR, "%s", inputStr) != 1);
        
    for(int i = 0; i < strlen(inputStr); ++i){
        if(inputStr[i] >= '0' &&inputStr[i] <= '9'){
            tempI = inputStr[i] - '0';
            numStack.push((double)tempI);
        }
        else if(inputStr[i] == '+'){
            if(opeStack.empty())
                opeStack.push('+');
            else {
                while(!opeStack.empty() && opeStack.top() != '('){
                    if(opeStack.top() == '+'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() + tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '-'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() - tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '*'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() * tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '/'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() / tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                }
                opeStack.push('+');
            }
        }
        else if(inputStr[i] == '-'){
            if(opeStack.empty())
                opeStack.push('-');
            else {
                while(!opeStack.empty() && opeStack.top() != '('){
                    if(opeStack.top() == '+'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() + tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '-'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() - tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '*'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() * tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '/'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() / tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                }
                opeStack.push('-');
            }
        }
        else if(inputStr[i] == '*'){
            if(opeStack.empty() || opeStack.top() == '+' || opeStack.top() == '-')
                opeStack.push('*');
            else {
                while(!opeStack.empty() && opeStack.top() != '+' && opeStack.top() != '-' && opeStack.top() != '('){
                    if(opeStack.top() == '+'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() + tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '-'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() - tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '*'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() * tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '/'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() / tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                }
                opeStack.push('*');
            }
        }
        else if(inputStr[i] == '/'){
            if(opeStack.empty() || opeStack.top() == '+' || opeStack.top() == '-')
                opeStack.push('/');
            else {
                while(!opeStack.empty() && opeStack.top() != '+' && opeStack.top() != '-' && opeStack.top() != '('){
                    if(opeStack.top() == '+'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() + tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '-'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() - tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '*'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() * tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                    else if(opeStack.top() == '/'){
                        tempD = numStack.top();
                        numStack.pop();
                        tempD = numStack.top() / tempD;
                        numStack.pop();
                        numStack.push(tempD);
                        opeStack.pop();
                    }
                }
                opeStack.push('/');
            }
        }
        else if(inputStr[i] == '(')
            opeStack.push('(');
        else if(inputStr[i] == ')'){
            while(opeStack.top() != '('){
                if(opeStack.top() == '+'){
                    tempD = numStack.top();
                    numStack.pop();
                    tempD = numStack.top() + tempD;
                    numStack.pop();
                    numStack.push(tempD);
                    opeStack.pop();
                }
                else if(opeStack.top() == '-'){
                    tempD = numStack.top();
                    numStack.pop();
                    tempD = numStack.top() - tempD;
                    numStack.pop();
                    numStack.push(tempD);
                    opeStack.pop();
                }
                else if(opeStack.top() == '*'){
                    tempD = numStack.top();
                    numStack.pop();
                    tempD = numStack.top() * tempD;
                    numStack.pop();
                    numStack.push(tempD);
                    opeStack.pop();
                }
                else if(opeStack.top() == '/'){
                    tempD = numStack.top();
                    numStack.pop();
                    tempD = numStack.top() / tempD;
                    numStack.pop();
                    numStack.push(tempD);
                    opeStack.pop();
                }
            }
            opeStack.pop();
        }   
    }
    while(!opeStack.empty()){
        if(opeStack.top() == '+'){
            tempD = numStack.top();
            numStack.pop();
            tempD = numStack.top() + tempD;
            numStack.pop();
            numStack.push(tempD);
            opeStack.pop();
        }
        else if(opeStack.top() == '-'){
            tempD = numStack.top();
            numStack.pop();
            tempD = numStack.top() - tempD;
            numStack.pop();
            numStack.push(tempD);
            opeStack.pop();
        }
        else if(opeStack.top() == '*'){
            tempD = numStack.top();
            numStack.pop();
            tempD = numStack.top() * tempD;
            numStack.pop();
            numStack.push(tempD);
            opeStack.pop();
        }
        else if(opeStack.top() == '/'){
            tempD = numStack.top();
            numStack.pop();
            tempD = numStack.top() / tempD;
            numStack.pop();
            numStack.push(tempD);
            opeStack.pop();
        }
    }

    fprintf(fileW, "%.2lf", numStack.top());

    fclose(fileW);
    fclose(fileR);
    return 0;
}