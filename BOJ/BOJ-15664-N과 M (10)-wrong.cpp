// normal wrong

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int N, M, valid[10], cache[10], numTable[10], permTable[10];
char str[100];
std::vector<std::string> archive;

bool same(){
    for(int i = 0; i < M; ++i)
        if(cache[i] != valid[i]) return false;
    return true;
}

int main() {
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i)
        std::cin >> numTable[i];
    
    std::sort(numTable, numTable + N);

    for(int i = 0; i < M; ++i)
        permTable[i] = 1;
    
    do{
        int ptr = 0;
        for(int i = 0; i < N; ++i)
            if(permTable[i] == 1)
                valid[ptr++] = numTable[i];
        
        if(same())
            continue;
        
        std::string temp = "";
        for(int i = 0; i < M; ++i){
            cache[i] = valid[i];
            temp += std::to_string(valid[i]);
            temp += " ";
        }
        temp.erase(temp.size() - 1);
        archive.push_back(temp);
    }while(std::prev_permutation(permTable, permTable + N));

    std::sort(archive.begin(), archive.end());
    for(int i = 0; i < archive.size(); ++i)
        std::cout << archive[i] << "\n";
    return 0;
}
