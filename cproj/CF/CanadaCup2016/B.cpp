/**
 *  GNU C++11	Accepted	31 ms	0 KB
 **/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int num[200];
char c;
int main(){
    num['a'] = 4;
    num['b'] = 5;
    num['c'] = 6;
    num['d'] = 3;
    num['e'] = 2;
    num['f'] = 1;
    scanf("%lld%c", &n,&c);
    ll past = n/4;
    ll time;
    if(n%4==3 || n%4==1){
        time = past * 4 + past * 12;
    }
    if(n%4==0){
        past --;
        time = past * 4 + 1 + (past*2+1)*6;
    }
    if(n%4==2){
        time = past * 4 + 1 + (past*2+1)*6;
    }
    time += num[c];
    cout << time << endl;
    return 0;
}

/// the simplest problem I thought.
