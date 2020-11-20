#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
//思路：先把前后的按照题目所说的填好，
//然后把中间的数字提取一下 就得到中间要填的数字
//时间复杂度O（n），空间O（n）
void solve(int a[],int len){//要处理的数组及长度
int posTail=len-1;
     int fillsuf;
     for(int i=len-1;i>=0;i--){
         if(a[i]!=-1){//找到后面需要填啥
             posTail=i;
             fillsuf=a[i];
             break;
         }
        
     }
      int pospre=0;
     int fillpre;
     for(int i=0;i<len;i++){
         if(a[i]!=-1){//先找到前面需要填啥
             pospre=i;
             fillpre=a[i];
             break;
         }
        
     }
     vector<int>num;//将数组中的数提取出来
     for(int i=pospre;i<=posTail;i++){
         if(a[i]==-1&&a[i-1]!=-1){
             num.push_back(a[i-1]);
         }
     }
     vector<int>fillmid;
     for(int i=1;i<num.size();i++){
        fillmid.push_back((num[i]+num[i-1])/2);//预处理出中间要填的数
     }
    
     for(int i=0;i<pospre;i++){
         a[i]=fillpre;//填写前面
     }
     
     for(int i=len-1;i>posTail;i--){
         a[i]=fillsuf;//填写后面面
     }
     
     int cnt=0;//要取的数的位置
     
     for(int i=pospre+1;i<=posTail;i++){
         if(a[i]==-1){//如果是-1就填上
           a[i]=fillmid[cnt];
         }
         else if(a[i]!=-1&&a[i-1]==-1){//说明要填新的
            cnt++;
         }
     }
}
void testIt(){

    printIt(a,size);
    
}
int main(){
    int a[]={-1,-1,10,-1,-1,30,-1,-1,-1,20,-1};

    return 0;
}