// normal wrong

#include<iostream>
#include<algorithm>

bool continuous(int* arr, int size){
	bool cont = false;
	for(int i = 0; i < size - 1; ++i)
		cont = (arr[i] == arr[i + 1] && arr[i] == 0) ? true : cont;
	return cont;
}
bool same(int* arr1, int* arr2, int size){
	int ans = 0;
	for(int i = 0; i < size; ++i)
		ans += (arr1[i] == arr2[i]) ? 1 : 0;
	return (ans == size) ? true : false;
}
void intCpy(int* dest, int* src, int size){
	for(int i = 0; i < size; ++i)
		dest[i] = src[i];
}

int main () {
	int tempAns, ans =-1, len, combTable[10], trace[10] = {0,};
	char mathExp[25];
	scanf("%d\n%s", &len, mathExp);
	if(len == 3){
		if(mathExp[1] == '*')
			printf("%d", (mathExp[0] - '0') * (mathExp[2] - '0'));
		else if(mathExp[1] == '-')
			printf("%d", (mathExp[0] - '0') - (mathExp[2] - '0'));
		else if(mathExp[1] == '+')
			printf("%d", (mathExp[0] - '0') + (mathExp[2] - '0'));
		return 0;
	}
	else if(len == 1){
		printf("%d", mathExp[0] - '0');
		return 0;
	}
	for(int z = 1; z <= (len / 2 + 1) / 2; ++z){
		for(int j = 0; j < z; ++j)
			combTable[j] = 0;
		for(int j = z; j < len / 2; ++j)
			combTable[j] = 1;
		do{
			if(same(combTable, trace, len / 2) || continuous(combTable, len / 2))
				continue;
			intCpy(trace, combTable, len / 2);
			tempAns = mathExp[0] - '0';
			for(int i = 0; i < len / 2; ++i){
				if(mathExp[i * 2 + 1] == '*'){
					if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '*'){
						tempAns *= (mathExp[(i + 1) * 2] - '0') * (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '-'){
						tempAns *= (mathExp[(i + 1) * 2] - '0') - (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '+'){
						tempAns *= (mathExp[(i + 1) * 2] - '0') + (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(combTable[i + 1])
						tempAns *= mathExp[(i + 1) * 2] - '0';
				}
				else if(mathExp[i * 2 + 1] == '-'){
					if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '*'){
						tempAns -= (mathExp[(i + 1) * 2] - '0') * (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '-'){
						tempAns -= (mathExp[(i + 1) * 2] - '0') - (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '+'){
						tempAns -= (mathExp[(i + 1) * 2] - '0') + (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(combTable[i + 1])
						tempAns -= mathExp[(i + 1) * 2] - '0';
				}
				else if(mathExp[i * 2 + 1] == '+'){
					if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '*'){
						tempAns += (mathExp[(i + 1) * 2] - '0') * (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '-'){
						tempAns += (mathExp[(i + 1) * 2] - '0') - (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(!combTable[i + 1] && mathExp[(i + 1) * 2 + 1] == '+'){
						tempAns += (mathExp[(i + 1) * 2] - '0') + (mathExp[(i + 1) * 2 + 2] - '0');
						++i;
					}
					else if(combTable[i + 1])
						tempAns += mathExp[(i + 1) * 2] - '0';
				}
			}
			ans = (tempAns > ans) ? tempAns : ans;
		}while(std::next_permutation(combTable, combTable + len / 2));
	}
	printf("%d", ans);
	return 0;
}
