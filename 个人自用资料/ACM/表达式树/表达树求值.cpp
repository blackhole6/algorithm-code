/*
  @author : blackhole6
  @description : Creat By blackhole6
  @date : 2019/11/26 16:13
*/

//表达式形如 9+(3-1)*3+1/2=，结束以一个单=结束

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define MAX 0x3f3f3f3f
using namespace std;
 struct  TNode{
    int flag;
    int data;//flag=0
    char ch;//flag=1
    struct TNode * lChild;//左孩子
    struct  TNode * rChild;//右孩子
};

int cal(struct TNode *root){
    if(root->flag==1){
        switch(root->ch){
            case '+':{
                return cal(root->lChild)+cal(root->rChild);
                break;
            }
            case '-':{
                return cal(root->lChild)-cal(root->rChild);
                break;
            }
            case '/':{
                return cal(root->lChild)/cal(root->rChild);
                break;
            }
            case '*':{
                return cal(root->lChild)*cal(root->rChild);
                break;
            }
        }
    }
    return root->data;
}
int check(char s[],int start,int end){
    int i;
    int sum=0;
    int flag=1;
    if(s[start]=='-'){
        flag=-1;
        start++;
    }
    for(i=start;i<=end;i++){
        if(!isdigit(s[i])) return MAX;
        sum=sum*10+s[i]-'0';
    }
    return sum*flag;
}
struct TNode * buildTree(char s[],int start,int end){
    struct TNode * root=(struct TNode *)malloc(sizeof(struct TNode));
    int cnt=0;
    int m;
    int i;
    if(start>end) return NULL;
    int posPlusOrSub=0;//加减号位置
    int numPlusOrSub=0;//加减号个数
    int posDivOrMul=0;//乘除号位置
    int numDivOrMul=0;//乘除号个数
    int num;
    num=check(s,start,end);
    if(num!=0x3f3f3f3f){//只有数字
        root->flag=0;
        root->data=num;
        root->lChild=NULL;
        root->rChild=NULL;
        return root;
    }
    //有操作符
    int in_brackets=0;//不在括号里的标识符
    for(int k=start;k<=end;k++){
        if(s[k]=='('){
            in_brackets++;
        }
        else if(s[k]==')'){
            in_brackets--;
        }
        if(!in_brackets){//括号之外
            if(s[k]=='+'||s[k]=='-'){
                posPlusOrSub=k;
                numPlusOrSub++;
            }
            else if(s[k]=='*'||s[k]=='/'){
                posDivOrMul=k;//乘除号位置
                numDivOrMul++;//乘除号个数
            }
        }
    }
    int pos_root;
    //寻找根节点 有加减用加减没加减用乘除
    if(numPlusOrSub){
        pos_root=posPlusOrSub;
    }
    else if(numDivOrMul){
        pos_root=posDivOrMul;
    }
    else{//找不到根 递归再找一次
        return buildTree(s,start+1,end-1);
    }
    root->flag=1;
    root->ch=s[pos_root];
    root->lChild = buildTree(s,start,pos_root-1);
    root->rChild = buildTree(s,pos_root+1,end);
    return root;
}
int main(int argc, char** argv) {
    while(1){
        char a[200];
        scanf("%s",a);
        if(strcmp(a,"=")==0){
            break;
        }
        int len=strlen(a);
        a[len-1]='\0';
        struct TNode* b=(struct TNode *)malloc(sizeof(struct TNode));
        b=buildTree(a,0,strlen(a)-1);
        printf("%d\n",cal(b));
    }
    return 0;
}
