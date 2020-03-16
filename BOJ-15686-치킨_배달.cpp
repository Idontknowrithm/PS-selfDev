#include<iostream>
#include<vector>
#include<algorithm>
#define IMAX 2147483647

typedef struct{
	int row, col;
}location;

bool same(int* a, int* b, int size){
	for(int i = 0; i < size; ++i)
		if(a[i] != b[i])
			return false;
	return true;
}

int main () {
	int N, M, inp, tempDist, tempAns, ans = IMAX, distance[13][100], combTable[13], trace[13];
	std::vector<location> chicken, house;

	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
	for(int u = 0; u < N; ++u){
		scanf("%d", &inp);
		if(inp == 1)
			house.push_back({i, u});
		else if(inp == 2)
			chicken.push_back({i, u});
	}
	for(int i = 0; i < chicken.size(); ++i)
	for(int u = 0; u < house.size(); ++u){
		distance[i][u] =  (chicken[i].row > house[u].row) ? chicken[i].row - house[u].row : house[u].row - chicken[i].row;
		distance[i][u] += (chicken[i].col > house[u].col) ? chicken[i].col - house[u].col : house[u].col - chicken[i].col;
	}
	for(int i = 0; i < 13; ++i)
		combTable[i] = trace[i] = 1;
	for(int i = 0; i < M; ++i)
		combTable[i] = 0;
	
	do{
		if(same(combTable, trace, chicken.size()))
			continue;
		for(int i = 0; i < chicken.size(); ++i)
			trace[i] = combTable[i];
		
		tempAns = 0;
		for(int i = 0; i < house.size(); ++i){
			tempDist = IMAX;
			for(int u = 0; u < chicken.size(); ++u){
				if(!combTable[u])
					tempDist = (tempDist > distance[u][i]) ? distance[u][i] : tempDist;				
			}
			tempAns += tempDist;
		}
		ans = (ans > tempAns) ? tempAns : ans;
	}while(std::next_permutation(combTable, combTable + chicken.size()));

	printf("%d", ans);
	return 0;
}
