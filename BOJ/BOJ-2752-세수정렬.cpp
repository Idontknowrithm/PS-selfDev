#include<iostream>
#include<algorithm>

int main () {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	std::sort(a, a + 3);
	printf("%d %d %d", a[0], a[1], a[2]);
}
