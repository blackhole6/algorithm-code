#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
const int maxn=1e6+5;
typedef long long ll;
using namespace std;

string as,cs,tempb,tempd,a,b,c,d;
char str1[maxn],str2[maxn],str3[maxn];
int x[maxn],y[maxn];
string minuss(string a,string b)
{
    int la=a.length(),lb=b.length(),lc,i;
    memset(y,0,sizeof(y));lc=max(la,lb);string ans;
    for (i=0;i<la;i++)x[la-i-1]=a[i]-48;
    for (i=0;i<lb;i++)y[lb-i-1]=b[i]-48;
    for (i=0;i<lc;i++)
    {
        x[i]-=y[i];
        if (x[i]<0)x[i+1]--,x[i]+=10;
    }
    while (!x[lc-1] && lc>1)lc--;
    for (i=lc-1;i+1;i--)ans.push_back(x[i]+48);
    return ans;
}
int main()
{
    int T;
    int ans;
    cin>>T;
    while(T--)
    {
        scanf("%s%s%s",str1,str2,str3);
        a=string(str1);
        b=string(str2);
        c=string(str3);
        int isok=0;
        as=a;
        cs=c;
        int cnt=(as.length()-cs.length());
        cnt=max(cnt,(int)(b.length()-as.length()));
        for(int i=1;i<=cnt;++i)
        {
            cs.push_back('0');
        }
        int cha=cs.length()-as.length();

        if(cha==0&&as[0]>cs[0])
        {
            cs.push_back('0');
            cha++;
        }
        if(cha>0&&as[0]>cs[0])
        {
            cha--;
        }
        for(int t=1;t<=cha;t++)
        {
            as.push_back('0');
        }
        d=minuss(cs,as);
        int flag=1;
        int id1=0;int id2=0;
        tempb=b;
        tempd=d;
        int len1=tempb.length();
        int len2=tempd.length();

        ans=0;
        if(len1>len2)
        {
            ans+=len1-len2;
        }
        while(flag&&id1<len1&&id2<len2)
        {
            if(tempb[id1]!=tempd[id2])
            {
                flag=0;
            }
            id1++;
            id2++;
        }
        if(len2>len1)
        {
            for(int i=len1;flag&&i<len2;++i)
            {
                if(tempd[i]!='0')
                {
                    flag=0;
                }
            }
        }else
        {
            for(int i=len2;flag&&i<len1;++i)
            {
                if(tempb[i]!='0')
                {
                    flag=0;
                }
            }
        }

        if(flag)
        {
            printf("%d %d %d\n",(as.length())-(a.length())+ans,(d.length()-b.length())+ans,cs.length()-c.length()+ans);
            isok=1;
        }
        if(!isok)
        {
            swap(a,b);
            as=a;
            cs=c;
            cnt=(as.length()-cs.length());
            cnt=max(cnt,(int)(b.length()-as.length()));
            for(int i=1;i<=cnt;++i)
            {
                cs.push_back('0');
            }
            cha=cs.length()-as.length();
            if(cha==0&&as[0]>cs[0])
            {
                cs.push_back('0');
                cha++;
            }
            if(cha>0&&as[0]>cs[0])
            {
                cha--;
            }
            for(int i=1;i<=cnt;++i)
            {
                as.push_back('0');
            }
            d=minuss(cs,as);
            flag=1;
            id1=0;id2=0;
            tempb=b;
            tempd=d;
            len1=tempb.length();
            len2=tempd.length();
            ans=0;
            if(len1>len2)
            {
                ans+=len1-len2;
            }
            while(flag&&id1<len1&&id2<len2)
            {
                if(tempb[id1]!=tempd[id2])
                {
                    flag=0;
                }
                id1++;
                id2++;
            }
            if(len2>len1)
            {
                for(int i=len1;flag&&i<len2;++i)
                {
                    if(tempd[i]!='0')
                    {
                        flag=0;
                    }
                }
            }else
            {
                for(int i=len2;flag&&i<len1;++i)
                {
                    if(tempb[i]!='0')
                    {
                        flag=0;
                    }
                }
            }
            if(flag)
            {
                printf("%d %d %d\n",(d.length()-b.length())+ans,(as.length())-(a.length())+ans,cs.length()-c.length()+ans);
                isok=1;
            }
        }
        if(!isok)
        {
            printf("-1\n");
        }
    }
    system("pause");
    return 0;

}