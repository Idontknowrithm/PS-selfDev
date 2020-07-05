// timeout

#include<iostream>
#include<algorithm>
#include<vector>

typedef struct{
	std::string type;
	int size;
}wear;

std::vector<wear> data;
bool found;

bool same(int* a, int* b, int size){
	for(int i = 0; i < size; ++i)
		if(a[i] != b[i])
			return false;
	return true;
}

int main () {
	int T, inputNum, ans, tempAns, combTable[30], trace[30];
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
		ans = 0;
		for(int z = 1; z <= data.size(); ++z){
			for(int u = 0; u < 30; ++u)
				combTable[u] = trace[u] = 1;
			for(int u = 0; u < z; ++u)
				combTable[u] = 0;
			do{
				if(same(combTable, trace, data.size()))
					continue;
				for(int i = 0; i < data.size(); ++i)
					trace[i] = combTable[i];
				
				tempAns = 1;
				for(int i = 0; i < data.size(); ++i){
					if(!combTable[i])
						tempAns *= data[i].size;
				}
				ans += tempAns;
			}while(std::next_permutation(combTable, combTable + data.size()));
		}
		std::cout << ans << "\n";
		data.clear();
	}
	return 0;
}
