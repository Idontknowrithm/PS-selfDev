#include<iostream>
#include<vector>
#include<algorithm>



int main () {
	bool can;
	int T, col, arr[100];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &col);
		for(int i = 0; i < col; ++i){
			scanf("%d", &arr[i]);
		}
		std::sort(arr, arr + col);
		can = true;
		for(int i = 1; i < col; ++i){
			if((arr[col - i] - arr[col - i - 1]) % 2 != 0){
				can = false;
				break;
			}
		}
		if(can)
			printf("YES\n");
		else 	
			printf("NO\n");
	}
	return 0;
}
