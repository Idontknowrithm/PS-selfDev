// printf랑 cin cout이랑 혼용하지 않도록 주의하자

#include<iostream>

int N, que[3000000];
int front, back, size;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::string P = "push", F = "front", B = "back", S = "size", E = "empty", PO = "pop";
    for(int i = 0; i < N; ++i){
        std::string input;
        std::cin >> input;
        if(input == P){
            int tmp;
            std::cin >> tmp;
            que[back++] = tmp;
            ++size;
        }
        else if(input == F){
            std::cout << ((size) ? que[front] : -1) << "\n";
        }
        else if(input == B){
            std::cout << ((size) ? que[back - 1] : -1) << "\n";
        }
        else if(input == S){
            std::cout << size << "\n";
        }
        else if(input == E){
            std::cout << ((size) ? 0 : 1) << "\n";
        }
        else if(input == PO){
            std::cout << ((size) ? que[front] : -1) << "\n";
            if(size){
                ++front;
                --size;
            }
        }
    }
    return 0;
}
