#include<iostream>
 
typedef struct {
	int t, l, h;
}costomer;
 
int main () {
	int T, num, initTem, max, min, curT = 0;
	bool possible;
	costomer data[105];
 
	scanf("%d", &T);
 
	while(T--){
		scanf("%d %d", &num, &initTem);
		for(int i = 0; i < num; ++i)
			scanf("%d %d %d", &data[i].t, &data[i].l, &data[i].h);
 
		max = min = initTem;
		curT = 0;
		possible = true;
		for(int i = 0; i < num; ++i){
			if((max < data[i].l && max + data[i].t - curT < data[i].l) ||
			   (min > data[i].h && min - data[i].t + curT > data[i].h)){
			   possible = false;
			   break;
			}
			max = (max + data[i].t - curT < data[i].h) ? max + data[i].t - curT : data[i].h;
			min = (min - data[i].t + curT > data[i].l) ? min - data[i].t + curT : data[i].l;
			curT = data[i].t;
		}
		if(!possible){
			printf("NO\n");
		}
		else 
			printf("YES\n");
	}
}
