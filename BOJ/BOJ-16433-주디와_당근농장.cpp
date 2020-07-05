#include<iostream>

int main () {
	int N, R, C;
	scanf("%d %d %d", &N, &R, &C);
	if((R % 2 == 1 && C % 2 == 1) || (R % 2 == 0 && C % 2 == 0)){
		for(int i = 0; i < N; ++i){
			for(int u = 0; u < N; ++u){
				if((i % 2 == 1 && u % 2 == 1) || (i % 2 == 0 && u % 2 == 0))
					printf("v");
				else 
					printf(".");
			}
			puts("");
		}
	} else {
		for(int i = 0; i < N; ++i){
			for(int u = 0; u < N; ++u){
				if((i % 2 == 1 && u % 2 == 1) || (i % 2 == 0 && u % 2 == 0))
					printf(".");
				else 
					printf("v");
			}
			puts("");
		}
	}
	return 0;
}
