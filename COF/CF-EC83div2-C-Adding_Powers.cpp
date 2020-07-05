#include<iostream>

int main () {
	bool possible;
	int T, n, Kmax, Ktrace[100];
	long long int k, num, index, arr[30], Ksquare[100]; //K의 지수값들
	scanf("%d", &T);
	index = 100000000;
	index *= 100000000;
	while(T--){
		scanf("%d %lld", &n, &k);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &arr[i]);
 
		num = k;
		Ksquare[0] = 1;
		for(int i = 1;; ++i){
			Ksquare[i] = num;
			if(num > index || num < 0){
				Kmax = i - 1;
				break;
			}
			num *= k;
		}
		for(int i = 0; i < 100; ++i)
			Ktrace[i] = 0;
 
		for(int i = 0; i < n; ++i){
			for(int u = 0; u < Kmax; ++u){
				if(!arr[i])
					break;
				num = Kmax + 1;
				while(Ksquare[--num] > arr[i]);
				arr[i] -= Ksquare[num];
				++Ktrace[num];
			}
		}
		possible = true;
		for(int i = 0; i <= Kmax; ++i)
			possible = (Ktrace[i] > 1) ? false : possible;
		if(possible)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
