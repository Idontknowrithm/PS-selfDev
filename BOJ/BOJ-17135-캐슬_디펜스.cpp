// 궁수들의 공격 알고리즘이 사전에 정해져있었음
// --> 궁수들의 공격이 겹치는 경우가 발생할 수 있다는 점을 간과
// 고등학교때부터 가지고있던 문제 조건을 제멋대로 해석하는 습관 

#include<iostream>
#include<algorithm>

int N, M, killed, index, field[20][20], battleField[20][20], queue[3][2];

void attack(int row, int col, int dist){
	for(int i = 1; i <= dist; ++i){
		for(int j = 0; j < i; ++j)
			if(row - j >= 0 && row - j < N && col - i + 1 + j >= 0 && col - i + 1 + j < M){
				if(battleField[row - j][col - i + 1 + j]){
					queue[index][0] = row - j;
					queue[index++][1] = col - i + 1 + j;
					return;	
				}
			}
		for(int j = 0; j < i - 1; ++j)
			if(row - i + 2 + j >= 0 && row - i + 2 + j < N && col + 1 + j >= 0 && col + 1 + j < M){
				if(battleField[row - i + 2 + j][col + 1 + j]){
					queue[index][0] = row - i + 2 + j;
					queue[index++][1] = col + 1 + j;
					return;		
				}
			}
	}
}
int overlap(){
	if(index == 0)
		return 0;
	else if(index == 1)
		return 1;
	else if(index == 2)
		if(queue[0][0] == queue[1][0] && queue[0][1] == queue[1][1])
			return 1;
		else 
			return 2;
	else if(index == 3)
		if(queue[0][0] == queue[1][0] && queue[0][1] == queue[1][1] &&
		   queue[1][0] == queue[2][0] && queue[1][1] == queue[2][1] &&
		   queue[0][0] == queue[2][0] && queue[0][1] == queue[2][1])
			return 1;
		else if((queue[0][0] == queue[1][0] && queue[0][1] == queue[1][1]) ||
				(queue[1][0] == queue[2][0] && queue[1][1] == queue[2][1]) ||
				(queue[0][0] == queue[2][0] && queue[0][1] == queue[2][1]))
			return 2;
		else 
			return 3;
}
bool elimination(int Rsize, int Csize){
	for(int i = 0; i < Rsize; ++i)
	for(int j = 0; j < Csize; ++j)
		if(battleField[i][j])
			return false;
	return true;
}
void march(int Rsize, int Csize){
	for(int i = Rsize - 2; i >= 0; --i)
		for(int j = 0; j < Csize; ++j)
			battleField[i + 1][j] = battleField[i][j];
	for(int i = 0; i < Csize; ++i)
		battleField[0][i] = 0;
}
bool same(int* a, int* b, int size){
	for(int i = 0; i < size; ++i)
		if(a[i] != b[i])
			return false;
	return true;
}
void intCpy(int* dest, int* src, int size){
	for(int i = 0; i < size; ++i)
		dest[i] = src[i];
}
void fieldCpy(int Rsize, int Csize){
	for(int i = 0; i < Rsize; ++i)
	for(int j = 0; j < Csize; ++j)
		battleField[i][j] = field[i][j];
}

int main () {
	int D, ans = -1, combTable[20], trace[20] = {0,};

	scanf("%d %d %d", &N, &M, &D);
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < M; ++j)
		scanf("%d", &field[i][j]);
	
	if(M == 3){
		++ans;
		for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			ans += field[i][j];
		printf("%d", ans);
		return 0;
	}
	
	for(int i = 0; i < M; ++i)
		combTable[i] = 1;
	combTable[0] = combTable[1] = combTable[2] = 0;

	do{
		if(same(combTable, trace, M))
			continue;
		intCpy(trace, combTable, M);
		fieldCpy(N, M);
		killed = 0;
		while(1){
			index = 0; 
			for(int i = 0; i < M; ++i)
				if(!combTable[i]){
					attack(N - 1, i, D);
				}
			if(index)
			killed += overlap();
			battleField[queue[0][0]][queue[0][1]] = 0;
			battleField[queue[1][0]][queue[1][1]] = 0;
			battleField[queue[2][0]][queue[2][1]] = 0;

			if(elimination(N, M))
				break;
			march(N, M);
		}
		ans = (killed > ans) ? killed : ans;
	}while(std::next_permutation(combTable, combTable + M));
	printf("%d", ans);
	return 0;
}
