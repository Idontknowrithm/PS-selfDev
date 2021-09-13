#include<iostream>
#include<cstring>

const int MAX = 105;
int T, N;
std::string cache[MAX];

std::string max_str(std::string a, std::string b){
    if(a.size() > b.size()) return a;
    else if(a.size() < b.size()) return b;
    else{
        for(int i = 0; i < a.size(); ++i)
            if(a[i] > b[i]) return a;
            else if(a[i] < b[i]) return b;
    }
    return a;
}
std::string min_str(std::string a, std::string b){
    if(a.size() > b.size()) return b;
    else if(a.size() < b.size()) return a;
    else{
        for(int i = 0; i < a.size(); ++i)
            if(a[i] > b[i]) return b;
            else if(a[i] < b[i]) return a;
    }
    return a;
}
std::string DP_max(int idx){
    if(!idx){
        std::string t("");
        return t;
    }
    std::string tmp("x");

    std::string &ret = cache[idx];
    if(ret != tmp) return ret;

    ret = "";
    if(idx >= 2 && idx != 3){
        tmp = "1";
        ret = max_str(ret, DP_max(idx - 2) + tmp);        
    }
    if(idx >= 3 && idx != 4){
        tmp = "7";
        ret = max_str(ret, DP_max(idx - 3) + tmp);
    }
    if(idx >= 4 && idx != 5){
        tmp = "4";
        ret = max_str(ret, DP_max(idx - 4) + tmp);    
    }
    if(idx >= 5 && idx != 6){
        tmp = "5";
        ret = max_str(ret, DP_max(idx - 5) + tmp);        
    }
    if(idx >= 6 && idx != 7){
        tmp = "9";
        ret = max_str(ret, DP_max(idx - 6) + tmp);
    }
    if(idx >= 7 && idx != 8){
        tmp = "8";
        ret = max_str(ret, DP_max(idx - 7) + tmp);   
    }
    return ret;
}
std::string DP_min(int idx){
    if(!idx){
        std::string t("");
        return t;
    }
    std::string tmp("x");

    std::string &ret = cache[idx];
    if(ret != tmp) return ret;

    ret = "99999999999999999999";
    if(idx >= 2 && idx != 3){
        tmp = "1";
        ret = min_str(ret, DP_min(idx - 2) + tmp);        
    }
    if(idx >= 3 && idx != 4){
        tmp = "7";
        ret = min_str(ret, DP_min(idx - 3) + tmp);
    }
    if(idx >= 4 && idx != 5){
        tmp = "4";
        ret = min_str(ret, DP_min(idx - 4) + tmp);    
    }
    if(idx >= 5 && idx != 6){
        tmp = "3";
        ret = min_str(ret, DP_min(idx - 5) + tmp);        
    }
    if(idx >= 6 && idx != 7){
        if(idx != 6){
            tmp = "0";
            ret = min_str(ret, DP_min(idx - 6) + tmp);
        }
        tmp = "6";
        ret = min_str(ret, DP_min(idx - 6) + tmp);
    }
    if(idx >= 7 && idx != 8){
        tmp = "8";
        ret = min_str(ret, DP_min(idx - 7) + tmp);   
    }
    return ret;
}

int main() {
    // 2: 1
    // 3: 7
    // 4: 4
    // 5: 3 5
    // 6: 6 9 0
    // 7: 8
    for(std::cin >> T; T > 0; --T){
        std::cin >> N;
        for(int i = 0; i < 105; ++i){
            std::string tmp("x");
            cache[i] = tmp;
        }
        std::cout << DP_min(N) << " ";
        for(int i = 0; i < 105; ++i){
            std::string tmp("x");
            cache[i] = tmp;
        }
        std::cout << DP_max(N) << "\n";   
    }
    return 0;
}
