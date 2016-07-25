#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define minD 562510
#define minK 760
#define INF 0x3f3f3f3f
int N, D, min[4*minD], a[minK][minK], ans[minK];
void init(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			std::cin>>a[i][j];
		}
		std::sort(a[i], a[i]+N);
	}
	for(D = 1; D < N*N+2; D<<=1);
	memset(min, 0x3f, sizeof(min[0])*2*D);
}
void update(int i){
	for(; i ^ 1; i>>=1){
		min[i >> 1] = std::min(min[i], min[i ^ 1]);
	}
}
int getid(){
	int i;
	for(i = 1; i < D; ){
		if(min[i << 1] == min[i]) i<<= 1;
		else i = i << 1 | 1;
	}
	return i;
}
void pop(){
	int i = getid();
	min[i] = INF, update(i);
}
void push(int x, int y, int v){
	int i = x* N + y;
	min[D + i] = v, update(D + i);
}
void top(int &x, int &y, int &v){
	int i = getid() - D;
	x = i / N, y = i % N, v = min[D + i];
}
void solve(){
	int x, y, v, cnt;
	for(int i = 1; i < N; i++){
		while(min[1] != INF) pop();
		cnt = 0;
		push(0, 0, a[i - 1][0] + a[i][0]);
		while(cnt < N){
			top(x, y, v), pop();
			ans[cnt++] = v;
			if(x < N) push(x + 1, y, a[i - 1][x + 1]+a[i][y]);
			if(y < N) push(x, y + 1, a[i - 1][x] + a[i][y+1]);
		}
		for(int j = 0; j < N; j++){
			a[i][j] = ans[j];
		}
	}
	printf("%d", a[N - 1][0]);
	for(int i = 1; i < N; i++) printf(" %d", a[N - 1][i]);
	puts("");
}

int main(){
	while(std::cin>>N){
		init();
		solve();
	}
	return 0;
}
