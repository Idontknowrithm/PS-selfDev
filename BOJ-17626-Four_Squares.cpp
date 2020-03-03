// DP 라는 건 생각해냈는데 구체적 알고리즘 생각 못해냄

#include<iostream>

int main(){
	int N, DPtable[50001];
	DPtable[0] = 0;
	
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		DPtable[i] = i;
		for(int u = 1; u * u <= i; ++u)
			DPtable[i] = (DPtable[i - u * u] + 1 < DPtable[i]) ? DPtable[i - u * u] + 1 : DPtable[i];
	}
	printf("%d", DPtable[N]);
	return 0;
}
