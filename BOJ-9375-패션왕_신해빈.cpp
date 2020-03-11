// 3개 원소의 A그룹과 2개 원소의 B그룹에서 공집합 제외 뽑는 개수 -> (3 + 1) * (2 + 1) - 1
// 문제상황 잘 보고 예외처리 정확하게

#include<iostream>
#include<vector>

typedef struct{
	std::string type;
	int size;
}wear;

std::vector<wear> data;
bool found;

int main () {
	int T, inputNum, ans, tempAns;
	std::string inp;
	wear temp;
	std::cin >> T;
	while(T--){
		std::cin >> inputNum;
		for(int i = 0; i < inputNum; ++i){
			std::cin >> inp >> inp;
			found = false;
			for(int u = 0; u < data.size(); ++u){
				if(data[u].type == inp){
					++data[u].size;
					found = true;
					break;
				}
			}
			if(!found){
				temp.size = 1;
				temp.type = inp;
				data.push_back(temp);
			}
		}
		ans = 1;
		for(int i = 0; i < data.size(); ++i)
			ans *= data[i].size + 1;

		std::cout << ans - 1 << "\n";
		data.clear();
	}
	return 0;
}
