// timeout
// 재귀 쓰니까 타임아웃, 이것도 궁수 공격 알고리즘은 무시

#include<iostream>
#include<algorithm>

int N, M, killed, field[20][20], battleField[20][20];
bool done;

void attackL(int row, int col, int dist){
	if(!dist)
		return;
	if(battleField[row][col] && !done){
		battleField[row][col] = 0;
		++killed;
		done = true;
	}
	attackL(row, col - 1, dist - 1);
	attackL(row - 1, col, dist - 1);
	attackL(row, col + 1, dist - 1);
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
			for(int i = 0; i < M; ++i)
				if(!combTable[i]){
					done = false;
					attackL(N - 1, i, D);
				}
			if(elimination(N, M))
				break;
			march(N, M);
		}
		ans = (killed > ans) ? killed : ans;
	}while(std::next_permutation(combTable, combTable + M));
	printf("%d", ans);
	return 0;
}
