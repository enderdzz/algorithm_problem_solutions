# include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int j = 0;
	while(n--){
		char word[1200] = {};
		scanf("%s", word);
		int l = strlen(word);
		char s1 = word[0], s2;
		int num = 1;
		int f = 0, ans = 0; 
		for(int i = 1; i < l; i++){
			if(word[i] != s1){
				num++;
				f = 2;
				if(num <= 2){s2 = word[i];}
				if(word[i] != s2){
					f = 1;
					break;
				}
			}
		}
		if(f == 2)
			ans = max(len, ans);
		if(!f)
			g[j++]=l;	
	}
	sort(g, g+j);
	printf("%d\n",g[j-1] + g[j-2] > ans ?g[j-1]+g[j-2]:ans)
		return 0;
}
