// 2372KB 468ms GNU G++11 4.9.2

#include <bits/stdc++.h>

using namespace std;

int path[201000], cost[201000], vis[201000];
int n, ans, cur;

queue<int> q;
void bfs(){
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(!vis[cur+1]){
            vis[cur+1] = 1;
            cost[cur+1] = cost[cur]+1;
            if(cur+1 < n)
            //notice that if you use cur+1>=n then break, that will not exec completely.
            //printf("== %d\n", cur+1);
            q.push(cur+1);

        }
        if(cur-1 >= 0 && !vis[cur-1]){
            vis[cur-1] = 1;
            cost[cur-1] = cost[cur] + 1;
            q.push(cur-1);
            //printf("-- %d\n", cur-1);
        }
        if(!vis[path[cur]-1]){
            vis[path[cur]-1] = 1;
            cost[path[cur]-1] = cost[cur] + 1;
            q.push(path[cur]-1);
            //printf(".. %d\n", path[cur]-1);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> path[i];
    }
    bfs();
    for(int i = 0; i < n-1; i++)
        cout << cost[i] << " ";
    cout << cost[n-1] << endl;
    return 0;
}
