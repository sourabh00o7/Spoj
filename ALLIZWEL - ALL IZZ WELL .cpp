#include<bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
bool vis[100][100];
string arr[100],s = "ALLIZZWELL";
#define valid(i,j,r,c)(i>=0&&i<r&&j>=0&&j<c)
bool present;

void f(int i,int j,int r,int c,int ind){
    int m,n,x,y;
    if(ind==9){
        present=true;
        return;
    }
    vis[i][j]=true;
    int a[]={-1,-1,-1,0,1,1,1,0},b[]={-1,0,1,1,1,0,-1,-1};
    for(m=0;m<8&&!present;m++){
        x=i+a[m];
        y=j+b[m];
        if(valid(x,y,r,c)&&s[ind+1]==arr[x][y]&&!vis[x][y]){
            f(x,y,r,c,ind+1);
        }
    }
    vis[i][j]=false;
}

int main(){
    int i,j,k,t,n,r,c;

    cin>>t;
    for(i=0;i<t;i++){
        present=false;
        cin>>r>>c;
        for(j=0;j<r;j++){
            for(k=0;k<c;k++){
                vis[j][k]=false;
            }
        }
        for(j=0;j<r;j++){
            cin>>arr[j];
        }
        for(j=0;j<r;j++){
            for(k=0;k<c;k++){
                if(arr[j][k]=='A'){
                    f(j,k,r,c,0);
                    if(present){
                        break;
                    }
                }
            }
            if(present){
                        break;
                    }
        }
        if(present){
                        cout<<"YES"<<endl;
                    }else{
                        cout<<"NO"<<endl;
                    }
    }
    
}