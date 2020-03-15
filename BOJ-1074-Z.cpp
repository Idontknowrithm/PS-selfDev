#include<iostream>

int N, R, C;

int main () {
	int search, cal, ans = 0;
	scanf("%d %d %d", &N, &R, &C);
	search = 1;
	for(int i = 0; i < N; ++i)
		search *= 2;
	while(search != 1){
		if	   (R < search / 2 && C >= search / 2){	// 1 quadrant
			cal = 1;
			for(int i = 0; i < N - 1; ++i)
				cal *= 4;
			ans += cal;
			C -= search / 2;
		}
		else if(R >= search / 2 && C < search / 2){	// 3 quadrant
			cal = 1;
			for(int i = 0; i < N - 1; ++i)
				cal *= 4;
			ans += cal * 2;
			R -= search / 2;
		}
		else if(R >= search / 2 && C >= search / 2){	// 4 quadrant
			cal = 1;
			for(int i = 0; i < N - 1; ++i)
				cal *= 4;
			ans += cal * 3;
			R -= search / 2;
			C -= search / 2;
		}
		
		search /= 2;
		--N;
	}
	printf("%d", ans);
	return 0;
}
