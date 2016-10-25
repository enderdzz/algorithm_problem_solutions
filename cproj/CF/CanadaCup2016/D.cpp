/**
 *  D - Contest Balloons	GNU C++11	Accepted	561 ms	17000 KB
 *  A very interesting problem I recently have seen.
 **/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct _Team{
    ll ballon;
    ll weight;
    bool operator < (const _Team &other) const {
        return ballon < other.ballon;          /// increase
    }
} Team;

typedef struct _Node {
    int num;
    ll val;
    bool operator < (const _Node &other) const {
        return val > other.val;                /// decrease
    }
} Node;

Team T[301000];
int n, index;
priority_queue<Node > q;
void solve(){
    // cout << index << " " << T[index].ballon << endl;
    for(int i = index; i < n; ++i)
        q.push(Node{i, T[i].weight - T[i].ballon + 1}); /// make the queue use the Node struct.
    int pos = index, ans = min(INT_MAX, (int)q.size() + 1);  /// ans presents T[0]'s ranking.
    while(!q.empty()){
        Node now = q.top();
        q.pop();

        // Do
        if(T[0].ballon < now.val){
            break;
        }
        T[0].ballon -= now.val;                  /// or T[0] will defeat this.
        index = upper_bound(T+1, T+n, T[0]) - T; /// update the index. It must smaller than the older.
        /* Most Important step! */
        for(int i = index; i < pos; ++i)         /// index
            q.push(Node{i, T[i].weight - T[i].ballon + 1}); /// newly add to the queue
        pos = index;
        ans = min(ans, (int)q.size() + 1);
    }
    cout << ans << endl;
}

void pre(){
    sort(T + 1, T + n);                 /// increase
    index = upper_bound(T+1, T+n, T[0]) - T; /// find the rank bigger than T[0].
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> T[i].ballon >> T[i].weight;
    }
    pre();
    solve();
    return 0;
}

/*
9
20 1000
32 37
20 38
40 1000
45 50
16 16
16 16
14 1000
2 1000
*/
