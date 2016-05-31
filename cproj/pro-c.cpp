#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char q[10], s[50];
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%s %s", q, s);
		if(!strcmp(q, "insert")){

		}
		else if(!strcmp(q, "search")){
			int flag = 0;

			if(flag)puts("Yes");
			else puts("No");
		}
		else if(!strcmp(q, "delete")){

		}
	}
	return 0;
}
