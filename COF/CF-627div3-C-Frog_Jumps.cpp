#include<iostream>
#include<vector>
#include<algorithm>

int main () {
	int T, ans, tempL, maxLcon, minRlen;
	std::string lane;
	std::cin >> T;
	while(T--){
		std::cin >> lane;
		maxLcon = 1;
		for(int i = 0; i < lane.size(); ++i){
			if(lane[i] == 'R'){
				minRlen = i + 1;
				break;
			}
		}
		for(int i = 0; i < lane.size(); ++i){
			if(lane[i] == 'L'){
				tempL = 1;
				while(lane[i] != 'R' && i < lane.size()){
					++tempL;
					++i;
				}
				maxLcon = (maxLcon < tempL) ? tempL : maxLcon;
			}
		}
		ans = (maxLcon < minRlen) ? minRlen : maxLcon;
		std::cout << ans << "\n";
	}
	return 0;
}
