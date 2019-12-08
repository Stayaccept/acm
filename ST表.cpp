#include<bits/stdc++.h>
using namespace std;

const int siz=100005;
int dp[siz][20];
void st(int n){
    int i,j;
    for(i=1;(1<<i)<=n;i++){
        for(j=1;j+(1<<i)-1<=n;j++){
            dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
        }
    }
}
int query(int u,int v){
    int k=0;
    while((1<<(1+k))<=v-u+1)
    k++;
    return max(dp[u][k],dp[v-(1<<k)+1][k]);
}
