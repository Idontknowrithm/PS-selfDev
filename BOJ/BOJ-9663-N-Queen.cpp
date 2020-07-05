// 확인 함수를 이중 포문으로 해서 시간초과 문제

#include<iostream>
#include<algorithm>

int N, ans, chessBoard[16];

bool possible(int Q){
	for(int u = 0; u < Q; ++u)
		if(chessBoard[Q] != -1 && chessBoard[u] != -1 && (std::abs(chessBoard[u] - chessBoard[Q]) == std::abs(u - Q) || chessBoard[u] == chessBoard[Q]))
			return false;
	return true;
}

void backtracking(int Q){
	if(Q == N){
		++ans;
		return;
	}
	for(int i = 0; i < N; ++i){
		chessBoard[Q] = i;
		if(possible(Q))
			backtracking(Q + 1);
		chessBoard[Q] = -1;
	}
}

int main () {
	for(int i = 0; i < 16; ++i)
		chessBoard[i] = -1;
	scanf("%d", &N);
	backtracking(0);
	printf("%d", ans);

	return 0;
}
