#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

long long Cal(long long n){
    long long i,j,k=0;
    if(n%4==1||n%4==2)
        k=1;
    for(i=2;i<=n;i<<=1)
    {
        j=(n-i+1)%(i<<1);
        if(j<=i&&j&1)
            k=k|i;
    }
    return k;
}
long long getXor(long long L, long long R) {
    long long i,j;
    i= Cal(L-1);
    j= Cal(R);
    return i^j;
}

int main(){
    long long l,r;
    cin>>l>>r;
    cout<<getXor(l,r)<<endl;
}