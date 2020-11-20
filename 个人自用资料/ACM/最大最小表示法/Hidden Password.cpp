//最小表示法模版
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
char str[maxn];
int Next[maxn];
void getNext( char T[],int len)
{
    int i = 0, j = -1;
    Next[0] = -1;
    while(i < len)
    {
        if(j == -1 || T[i] == T[j])
        {
            i++,j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}

int getMin(int len) {
    int i = 0, j = 1;
    int l;
    while (i < len && j < len) {
        for (l = 0; l < len; l++)
            if (str[(i + l) % len] != str[(j + l) % len]) break;
        if (l >= len) break;
        if (str[(i + l) % len] > str[(j + l) % len]) {
            if (i + l + 1 > j) i = i + l + 1;
            else i = j + 1;
        }
        else if (j + l + 1 > i) j = j + l + 1;
        else j = i + 1;
    }
    return i < j ? i : j;
}

int getMax(int len) {
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = str[(i + k) % len] - str[(j + k) % len];
        if (!t) k++;
        else {
            if (t > 0) {
                if (j + k + 1 > i) j = j + k + 1;
                else j = i + 1;
            }
            else if (i + k + 1 > j) i = i + k + 1;
            else i = j + 1;
            k = 0;
        }
    }
    return i < j ? i : j;

}
int main(){
    int T;
    cin>>T;
    while(T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
//        int len = strlen(str);
//        for(int i=0;i<=len;i++){
//            Next[i]=0;
//        }
        int ans1 = getMin(n);
//        int ans2 = getMax(len);
//        getNext(str,len);
//        int temp=len-Next[len];
//        int ans=1;
//        if(len%temp==0){
//            ans=len/temp;
//        }
//        printf("%d %d %d %d\n",ans1+1,ans,ans2+1,ans);
          printf("%d\n",ans1);
    }

    return 0;
}