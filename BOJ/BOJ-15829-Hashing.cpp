#include<iostream>
#include<cstring>

int main () {
	long long int cal, ans = 0;
	char str[51];
	scanf("%lld\n%s", &cal, str);
	for(int i = 0; i < strlen(str); ++i){
		cal = str[i] - 'a' + 1;
		for(int j = 0; j < i; ++j){
			cal *= 31;
			cal %= 1234567891;
		}
		ans += cal;
		ans %= 1234567891;	
	}
	ans %= 1234567891;
	printf("%lld", ans);
	return 0;
}
