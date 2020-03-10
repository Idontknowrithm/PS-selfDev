#include<iostream>
 
int main () {
	int T, N, M;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		if(N % M == 0)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
