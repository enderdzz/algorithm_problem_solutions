#include <iostream>
#include <cstdio>
#include <set>
#define ll long long 

using namespace std;

multiset<ll> eg;

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
	ll sum = 0;
	multiset<ll>::iterator iter = eg.begin();
	if(n <= k){
		multiset<ll>::reverse_iterator iter2;
		cout<<*eg.rbegin()<<endl;
		return 0;
	}
	while(te--){
		sum = *eg.begin();
		//cout<<"++++++"<<*eg.begin()<<endl;
		eg.erase(eg.lower_bound(sum));
		sum += *eg.begin();
		//cout<<"------"<<*eg.begin()<<endl;
		eg.erase(eg.lower_bound(*eg.begin()));
		eg.insert(sum);
	}
	multiset<ll>::reverse_iterator iter2 = eg.rbegin();
	cout<<*iter2<<endl;
	return 0;
}
