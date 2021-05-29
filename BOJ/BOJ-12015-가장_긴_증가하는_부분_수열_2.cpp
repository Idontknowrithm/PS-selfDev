#include<iostream>
#include<vector>
#include<algorithm>

int N;
std::vector<int> seq;

int main() {
    int input;
    seq.push_back(-1);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &input);
        if(seq[seq.size() - 1] < input)
            seq.push_back(input);
        else{
            (*std::lower_bound(seq.begin(), seq.end(), input)) = input;
        }
    }
    printf("%d", seq.size() - 1);
    return 0;
}
