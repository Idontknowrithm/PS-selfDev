#include<iostream>
#include<set>

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, inp, set[21] = {0,};
    std::string str;
    
    std::cin >> M;
    while(M--){
        std::cin >> str;
        if(str == (std::string)"add"){
            std::cin >> inp;
            set[inp] = 1;
        }
        else if(str == (std::string)"remove"){
            std::cin >> inp;
            set[inp] = 0;
        }
        else if(str == (std::string)"check"){
            std::cin >> inp;
            std::cout << set[inp] << "\n";
        }
        else if(str == (std::string)"toggle"){
            std::cin >> inp;
            set[inp] ^= 1;
        }
        else if(str == (std::string)"all"){
            set[1] = 1;  set[2] = 1;
            set[3] = 1;  set[4] = 1;
            set[5] = 1;  set[6] = 1;
            set[7] = 1;  set[8] = 1;
            set[9] = 1;  set[10] = 1;
            set[11] = 1; set[12] = 1;
            set[13] = 1; set[14] = 1;
            set[15] = 1; set[16] = 1;
            set[17] = 1; set[18] = 1;
            set[19] = 1; set[20] = 1;
        }
        else if(str == (std::string)"empty"){
            set[1] = 0;  set[2] = 0;
            set[3] = 0;  set[4] = 0;
            set[5] = 0;  set[6] = 0;
            set[7] = 0;  set[8] = 0;
            set[9] = 0;  set[10] = 0;
            set[11] = 0; set[12] = 0;
            set[13] = 0; set[14] = 0;
            set[15] = 0; set[16] = 0;
            set[17] = 0; set[18] = 0;
            set[19] = 0; set[20] = 0;
        }
    }
    return 0;
}
