//构造题
//给定一个r和c，让你构造出一个矩阵，使得每一行和每一列的GCD都不相同，并且使最大的GCD尽可能的小
//思路
//第一行为 r+1......r+c
//第二行为 2*(r+1)....2*(r+c)
//.......这样构造的基础使相邻两个数的gcd为1
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<iostream>
using namespace std;
typedef long long ll;

ll Mat[505][505];
int main(){
    int l,r;
    cin>>l>>r;
    ll s=1;
    if(l==1&&r==1){
        puts("0");
        return 0;
    }
    int flag=0;
    if(l>r){
        swap(l,r);
        flag=1;
    }
    for(int t=0;t<l;t++){
        for(int j=0;j<r;j++){
           Mat[t][j]=(l+1+j)*s;
        }
        s++;
    }
    if(flag){
        for(int t=0;t<r;t++){
            for(int j=0;j<l;j++){
           cout<<Mat[j][t]<<" ";
           }
        cout<<endl;
        }
    }
    else{
    for(int t=0;t<l;t++){
        for(int j=0;j<r;j++){
           cout<<Mat[t][j]<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}
