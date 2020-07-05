#include<iostream>

long long int five(long long int n){
	long long int numOfFive = 0;
	for(long long int i = 5; i <= n; i *= 5)
		numOfFive += n / i;
	return numOfFive;
}
long long int two(long long int n){
	long long int numOfTwo = 0;
	for(long long int i = 2; i <= n; i <<= 1){
		numOfTwo += n / i;
	}
	return numOfTwo;
}
int main () {
	long long int n, m, ans[7];
	scanf("%lld %lld", &n, &m);
	ans[0] = five(n);
	ans[1] = five(m);
	ans[2] = five(n - m);
	ans[3] = two(n);
	ans[4] = two(m);
	ans[5] = two(n - m);
	for(int i = 0; i < 6; ++i)
	ans[6] = (ans[0] - ans[1] - ans[2] < ans[3] - ans[4] - ans[5]) ? ans[0] - ans[1] - ans[2] : ans[3] - ans[4] - ans[5];
	printf("%lld", ans[6]);
	return 0;
}
