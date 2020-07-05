#include<iostream>
#include<algorithm>
#include<vector>

int main () {
    int N, max = -1;
    std::vector<std::string> library, cleanUp;
    std::string inp; std::vector<int> overlap;
    std::cin >> N;
    while(N--){
        std::cin >> inp;
        library.push_back(inp);
    }
    std::sort(library.begin(), library.end());
    cleanUp.push_back(library[0]);
    overlap.push_back(1);
    for(int i = 1; i < library.size(); ++i){
        if(library[i] == cleanUp[cleanUp.size() - 1]){
            ++overlap[overlap.size() - 1];
        }
        else {
            cleanUp.push_back(library[i]);
            overlap.push_back(1);
        }
    }
    for(int i = 0; i < overlap.size(); ++i)
        max = (overlap[i] > max) ? overlap[i] : max;
    for(int i = 0; i < overlap.size(); ++i)
        if(max == overlap[i]){
            std::cout << cleanUp[i];
            return 0;
        }
}
