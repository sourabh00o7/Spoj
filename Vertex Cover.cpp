#include<bits/stdc++.h>
using namespace std;
vector<int> v[100000];
int a[100000][2],b[100000];
int f(int x,int y,int z){
    int p,b,c,i;
  
    if(a[x][z]!=-1){
       
        return a[x][z];
    }
    p=INT_MAX;
         b=INT_MAX;

    c=INT_MAX;

    
 
    if(z==1){
        p=0;
        for(i=0;i<v[x].size();i++){
            if(v[x][i]!=y){
            p=p+f(v[x][i],x,0);}
        }
        b=1;
        for(i=0;i<v[x].size();i++){
            if(v[x][i]!=y){
            b=b+f(v[x][i],x,1);}
        }
        b=min(p,b);
        
    }else{
        c=1;
        for(i=0;i<v[x].size();i++){
             if(v[x][i]!=y){
            c=c+f(v[x][i],x,1);}
        }
    }
   
    c=min(b,c);
    a[x][z]=c;
   
    return c;
    
    
}
int main(){
    int i,j,k,t,n,m;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>j;
        cin>>k;
        v[j].push_back(k);
        v[k].push_back(j);
    }
    memset(a,-1,sizeof(a));
    j=0;
   for(i=0;i<v[1].size();i++){
      j=j+ f(v[1][i],1,0);
   }
   k=1;
    memset(a,-1,sizeof(a));

   for(i=0;i<v[1].size();i++){
      k=k+ f(v[1][i],1,1);
   }
   
   cout<<min(j,k);
}