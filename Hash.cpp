#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull base=131;
const ull mod=212370440130137957ll;
ull a[10005];
char s[10005];
ull Hash(char s[]){
    int i;
    ull ans=0;
    for(i=0;s[i];i++)
    ans=(ans*base+(ull)s[i])%mod;
    return ans;
}
int main(){
    int i,n,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        a[i]=Hash(s);
    }
    sort(a,a+n);
    ans=1;
    for(i=1;i<n;i++){
        if(a[i]!=a[i-1])
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
