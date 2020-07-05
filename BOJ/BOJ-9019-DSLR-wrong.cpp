// normal wrong

#include<iostream>
#include<queue>
#include<algorithm>

typedef struct{
    std::string str;
    int index;
}data;

int T, src, dest;
const int M = 100000000;
data set[10000];

void find(){
    std::queue<int> bfs;
    int idx, tempI; std::string s, tempS;
    bfs.push(src);

    while(!bfs.empty()){
        idx = bfs.front();
        bfs.pop();
        //S
        if(set[(idx - 1) % 10000].index == M || set[(idx - 1) % 10000].index > set[idx].index + 1){
            tempS = set[idx].str;
            tempS += "S";
            set[(idx - 1) % 10000].index = set[idx].index + 1;
            set[(idx - 1) % 10000].str = tempS;
            bfs.push((idx - 1) % 10000);
        }
        //D
        if(set[(idx * 2) % 10000].index == M || set[(idx * 2) % 10000].index > set[idx].index + 1){
            tempS = set[idx].str;
            tempS += "D";
            set[(idx * 2) % 10000].index = set[idx].index + 1;
            set[(idx * 2) % 10000].str = tempS;
            bfs.push((idx * 2) % 10000);
        }
        //L
        tempI = (idx * 10 + (idx / 1000)) % 10000;
        if(set[tempI].index == M || set[tempI].index > set[idx].index + 1){
            tempS = set[idx].str;
            tempS += "L";
            set[tempI].index = set[idx].index + 1;
            set[tempI].str = tempS;
            bfs.push(tempI);
        }
        //R
        tempI = ((idx % 10) * 10000 + idx) / 10; 
        if(set[tempI].index == M || set[tempI].index > set[idx].index + 1){
            tempS = set[idx].str;
            tempS += "R";
            set[tempI].index = set[idx].index + 1;
            set[tempI].str = tempS;
            bfs.push(tempI);
        }
    }
}

int main () {
    for(std::cin >> T; T > 0; --T){
        std::cin >> src >> dest;

        for(int i = 0; i < 10000; ++i){
            set[i].index = M;
            set[i].str = "";
        }
        set[src].index = 0;
        set[src].str = "";

        find();

        std::cout << set[dest].str << "\n";
    }
}
