#include<bits/stdc++.h>
using namespace std;

const int siz=11000005;
int a[siz<<1];
char s[siz<<1],S[siz<<1];
int manacher(int len){
    int i,id,mx,ans;
    id=mx=ans=0;
    for(i=0;i<len;i++){
        if(i<mx)
        a[i]=min(a[(id<<1)-i],mx-i);
        else
        a[i]=1;
        while(s[i-a[i]]==s[i+a[i]])
        a[i]++;
        if(i+a[i]>mx){
            id=i;
            mx=i+a[i];
        }
        ans=max(ans,a[i]-1);
    }
    return ans;
}
int main(){
    int i,len;
    scanf("%s",S);
    s[0]='$',s[1]='#';
    len=2;
    for(i=0;S[i];i++){
        s[len++]=S[i];
        s[len++]='#';
    }
    s[len++]='#';
    printf("%d\n",manacher(len));
    return 0;
}
