// normal wrong
// 변수 초기화 간과

#include<iostream>
#include<vector>

char IOI[1000001];

int main () {
	std::vector<int> contIOI;
	int N, len, temp, ans = 0, cont = 0;
	bool last = false;
	scanf("%d\n%d\n%s", &N, &len, IOI);
	for(int i = 2; i < len; ++i){
		if(IOI[i - 2] == 'I' && IOI[i - 1] == 'O' && IOI[i] == 'I'){
			if(last){
				contIOI.push_back(++cont);
			}
			else{
				last = true;
				cont = 1;
				contIOI.push_back(cont);
			}
		}
		else if(!(IOI[i - 2] == 'O' && IOI[i - 1] == 'I' && IOI[i] == 'O')){
			last = false;
		}
	}
	if(contIOI.size() == 1){
		printf("1");
		return 0;
	}
	else if(contIOI.size() == 0){
		printf("0");
		return 0;
	}
	for(int i = 1; i < contIOI.size(); ++i){
		if(contIOI[i] > contIOI[i - 1]){
			temp = contIOI[i];
		}
		else{
			ans += (temp - N + 1 > 0) ? temp - N + 1 : 0;
		}
	}
	ans += (contIOI[contIOI.size() - 1] - N + 1 > 0) ? contIOI[contIOI.size() - 1] - N + 1 : 0;
	printf("%d", ans);
	return 0;
}
