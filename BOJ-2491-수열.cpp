#include<iostream>

int main () {
	int N, greater = 1, lessor = 1, ansG = 1, ansL = 1, arr[100010];

	scanf("%d\n%d", &N, &arr[0]);
	for(int i = 1; i < N; ++i){
		scanf("%d", &arr[i]);
		greater += (arr[i - 1] > arr[i]) ? 0 : 1;
		lessor  += (arr[i - 1] < arr[i]) ? 0 : 1;
		if(arr[i - 1] > arr[i]){
			ansG = (greater > ansG) ? greater : ansG;
			greater = 1;
		}
		if(arr[i - 1] < arr[i]){
			ansL = (lessor > ansL) ? lessor : ansL;
			lessor = 1;
		}
	}
	ansL = (lessor > ansL) ? lessor : ansL;
	ansG = (greater > ansG) ? greater : ansG;
	
	printf("%d", (ansG > ansL) ? ansG : ansL);

	return 0;
}
