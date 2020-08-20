// 하아니 endl 대신에 "\n" 써야 시간 줄어드는 것 같다...

#include<iostream>

int T, n1, n2, table[1000005];

int main () {
    table[0] = table[1] = 0;
    table[2] = 1;
    table[3] = 3;
    table[4] = 2;
    table[5] = 5;
    for(int i = 6; i < 1000001; ++i){
        table[i] = (i & 1) ? table[(i + 1) / 2] + 2 : table[i / 2] + 1;
    }
    for(int i = 2; i < 1000001; ++i){
        table[i] += table[i - 1];
    }

    std::cin >> T;
    for(int z = 0; z < T; ++z){
        std::cin >> n1 >> n2;
        
        std::cout << "Case #" << z + 1 << "\n";
        std::cout << table[n2] - table[n1 - 1] << "\n";     
    }
    return 0;
}
