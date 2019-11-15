#include<bits/stdc++.h>
using namespace std;

const int siz=1000005;
int nex[siz];
char S[siz],T[siz];
void getnext(int len){
    int i,j;
    j=-1,i=0;
    nex[0]=-1;
    while(i<len){
        if(j==-1||T[i]==T[j])
        nex[++i]=++j;
        else
        j=nex[j];
    }
}
void kmp(int len_s,int len_t){
    int i,j,tmp;
    getnext(len_t);
    i=j=0;
    while(i<len_s){
        if(j==-1||S[i]==T[j])
        i++,j++;
        else
        j=nex[j];
        if(j==len_t){
            printf("%d\n",i-len_t+1);           //所有匹配位置
            j=nex[j-1];
            i--;
        }
    }
}
