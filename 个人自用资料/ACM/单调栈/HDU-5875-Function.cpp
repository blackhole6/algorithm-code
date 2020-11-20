//单调栈
#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1e5+5;
using namespace std;
int R[maxn];
int a[maxn];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int t=1;t<=n;t++)
        {
            scanf("%d",&a[t]);
        }
        stack<int>s;
        for(int t=n; t>=1; t--)
         {
			while(s.size()&&a[s.top()]>a[t]) {
				s.pop();
			}
			if(s.empty())
				R[t]=n;
			else {
				R[t]=s.top();
			}
			s.push(t);
		}
        int m;
        scanf("%d",&m);
        int l,r;
        while(m--)
        {
            scanf("%d%d",&l,&r);
            int pos=l;
            int ans=a[l];
            if(l==r)
            {
                printf("%d\n",a[l]);
                continue;
            }
            while(pos<r)
            {
                if(R[pos]>r)
                {
                    break;
                }
                ans=ans%a[R[pos]];
                pos=R[pos];
            }
            printf("%d\n",ans%a[r]);
        }
    }
    system("pause");
    return 0;
}