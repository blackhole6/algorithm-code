//DFS序
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
ll const INF = 1e18;
int const MAX = 100005;
int n, m;
ll a[MAX], sum[MAX << 2], lazy[MAX << 2], dis[MAX];
int l[MAX], r[MAX], nd[MAX], num;
int head[MAX], cnt;
 
struct EDGE
{
    int to, nxt, val;
}e[MAX << 1];
 
void Init()
{
    num = 0;
    cnt = 0;
    memset(head, -1, sizeof(head));
}
 
void Add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt ++;
}
 
void DFS(int u, int fa)
{
    num ++;
    l[u] = num;
    nd[num] = u;
    for(int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if(v != fa)
        {
            dis[v] = dis[u] + a[v];
            DFS(v, u);
        }
    }
    r[u] = num;
}
 
void PushUp(int rt)
{
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
    return;
}
 
void PushDown(int rt)
{
    if(lazy[rt])
    {
        sum[rt << 1] += lazy[rt];
        sum[rt << 1 | 1] += lazy[rt];
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
    return;
}
 
void Build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if(l == r)
    {
        sum[rt] = dis[nd[l]];
        return;
    }
    int mid = (l + r) >> 1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}
 
void Update(int L, int R, int val, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        lazy[rt] += val;
        sum[rt] += val;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(rt);
    if(L <= mid)
        Update(L, R, val, lson);
    if(mid < R)
        Update(L, R, val, rson);
    PushUp(rt);
}
 
ll Query(int L, int R, int l ,int r, int rt)
{
    if(L <= l && r <= R)
        return sum[rt];
    int mid = (l + r) >> 1;
    PushDown(rt);
    ll ans = -INF;
    if(L <= mid)
        ans = max(ans, Query(L, R, lson));
    if(mid < R)
        ans = max(ans, Query(L, R, rson));
    return ans;
}
 
int main()
{
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++)
    {
        printf("Case #%d:\n", ca);
        Init();
        int x, y;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d", &x, &y);
            Add(x, y);
            Add(y, x);
        }
        for(int i = 0; i < n; i++)
            scanf("%I64d", &a[i]);
        dis[0] = a[0];
        DFS(0, -1);
        Build(1, n, 1);
        while(m --)
        {
            int tp, x, y;
            scanf("%d", &tp);
            if(tp == 1)
            {
                scanf("%d", &x);
                printf("%I64d\n", Query(l[x], r[x], 1, n, 1));
            }
            else
            {
                scanf("%d %d", &x, &y);
                Update(l[x], r[x], y - a[x], 1, n, 1);
                a[x] = y;
            }
        }
    }
}