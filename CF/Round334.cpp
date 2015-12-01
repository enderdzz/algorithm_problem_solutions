#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

multiset<int> eg;
int temp[100100];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		eg.insert(t);
	}
	int te = n-k;
	int sum = 0 ;
	multiset<int>::iterator iter = eg.begin();
	while(te--){
		sum = 0;
		int cnt = 0 ;
		for(iter = eg.begin(); iter != eg.end()&& cnt<2 ; iter++){
			sum+=*iter;
			//cout<<*iter<<endl;
			cnt++;
			eg.erase(eg.lower_bound(*iter));
		}
		eg.insert(sum);
	}
	for(iter = eg.begin();iter != eg.end(); iter++){
		temp[k++]=*iter;
	}
	cout<<temp[k-1]<<endl;
	return 0;
}
