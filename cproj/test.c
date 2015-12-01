#include <stdio.h>

int f(int n){
	int b = 0;
	//if (b != 0){
	//	return 0; 
	//}
	while(n){
		b += n%10;
		n = n/10;
	}
	return b;
}

int main(){
	int a;
	scanf("%d", &a);
	if(a >= 10){
		while(a >= 10){
			a = f(a);
			printf("%d\n", a);
			if(a>100)break;
		}
		printf("%d\n", a);
	}
	else printf("%d\n", a);
	return 0;
}
