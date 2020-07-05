#include<iostream>
#include<stack>
#include<vector>

int main () {
	std::vector<int> data;
	std::stack<int> stk;
	int inp, T, index, pushNum = 0;
	bool table[100001];

	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		table[i] = false;
	for(int i = 0; i < T; ++i){
		scanf("%d", &inp);
		data.push_back(inp);
	}
	table[data[0]] = true;
	for(int i = 1; i < T; ++i){
		if(data[i] < data[i - 1]){
			for(int j = 0; j < data[i - 1] - data[i]; ++j){
				if(!table[data[i - 1] - j]){
					printf("NO");
					return 0;
				}
			}
			table[data[i]] = true;
		}
		else{
			table[data[i]] = true;
		}
	}
	for(int z = 0; z < T; ++z){
		while(pushNum < data[z]){
			printf("+\n");
			stk.push(++pushNum);
		}
		while(stk.top() != data[z]){
			printf("-\n");
			stk.pop();
		}
		printf("-\n");
		stk.pop();
	}
	return 0;	
}
