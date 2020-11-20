//一个有向图，n个点m条边，无自环，无重边，让你使得可能形成的环的颜色不能是一种颜色
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
vector<pair<int, int>> G[maxn];
int du[maxn];
int vis[maxn];
int n, m;
bool TPsort(){
    queue<int> q;
    for (int t = 1; t <= n; t++) {
        if (du[t] == 0){
            q.push(t);
        }
    }
    int cnt = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        cnt++;
        for (int t = 0; t < G[now].size(); t++){
            vis[G[now][t].second] = 1;
            int to = G[now][t].first;
            du[to]--;
            if (du[to] == 0){
                q.push(to);
            }
        }
    }
    if (cnt != n){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    memset(du, 0, sizeof(du));
    cin >> n >> m;
    int x, y;
    for (int t = 0; t < m; t++){
        scanf("%d%d", &x, &y);
        G[x].push_back(make_pair(y, t));
        du[y]++;
    }
    if (!TPsort()){
        puts("1");
        for (int t = 0; t < m; t++){
            printf("1 ");
        }
    }
    else{
        puts("2");
        for (int t = 1; t <= n; t++)
            for (int j = 0; j < G[t].size(); j++){
                int id = G[t][j].second;
                int to = G[t][j].first;
                if (!vis[id]){
                    if (t < to)
                        vis[id] = 1;
                    else
                        vis[id] = 2;
                }
            }
        for (int t = 0; t < m; t++){
            printf("%d ", vis[t]);
        }
    }
    return 0;
}
