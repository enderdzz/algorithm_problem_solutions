/**
 *  GNU C++11	Accepted	15 ms	0 KB
 **/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char s[120];
int len, rep;
int vis[200];
bool check(){
    for(int i = 0; i < len; ++i){
        if(s[i] == s[i+1]){
            return false;
        }
        if(!vis[s[i]])
            vis[s[i]] = i+1;   //first
        else
            rep = i+1;      //second
    }
    return true;
}

void solve(){
    int first = vis[s[rep-1]], second = rep;
    int delta = second - first-1;
    int row = delta/2 + first;
    if(row < 13){
        int d1 = 13 - row;
        int i = 0;
        while(d1){
            printf("%c",s[len-d1]);
            d1--;
        }
        for(int i = 0; i < row; i++)
            printf("%c", s[i]);
        puts("");
        for(int i = len-(13-row)-1; i >= row; i--)
            if(i!=(second-1))printf("%c", s[i]);

        puts("");
    }
    else if(row == 13){
        for(int i = 0; i < row; i++)
            printf("%c", s[i]);
        puts("");
        for(int i = row+13; i >= row; i--)
            if(i!=(second-1))printf("%c", s[i]);
        puts("");
    }
    else {
        int d2 = row - 13;
        int i = 0;
        while(d2){
            printf("%c",s[d2-1]);
            d2--;
        }
        for(int i = 26; i >= row; i--)
            if(i!=(second-1))printf("%c", s[i]);
        puts("");
        for(int i = row-13; i < row; i++)
            printf("%c", s[i]);

        puts("");
    }
}

int main(){
    cin >> s;
    len = strlen(s);
    if(check()){
        solve();
    }
    else puts("Impossible");
    return 0;
}

/// A implement problem.
