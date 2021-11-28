#include<iostream>

const int MAX = 1000005;
int pi[MAX];

void failure(const std::string str){
    int N = str.size(), begin = 1, matched = 0;

    while(begin + matched < N){
        if(str[begin + matched] == str[matched]){
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else{
            if(!matched)
                ++begin;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}
