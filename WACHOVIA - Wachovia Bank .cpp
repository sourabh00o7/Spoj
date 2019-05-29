#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,t,m,w;
    int arr[1005][55];
    int wt[55],val[55];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>w>>m;
        for(j=1;j<=m;j++){
            cin>>wt[j]>>val[j];
        }
        for(j=0;j<=w;j++){
            for(k=0;k<=50;k++){
                arr[j][k]=0;
            }
        }
        for(j=0;j<=w;j++){
            for(k=0;k<=m;k++){
                if(j==0||k==0){
                    arr[j][k]=0;
                }else{
                    if(wt[k]<=j){
                    arr[j][k]=max(arr[j][k-1],val[k]+arr[j-wt[k]][k-1]);}else{
                        arr[j][k]=arr[j][k-1];
                    }
                }
            }
        }
        cout<<"Hey stupid robber, you can get "<<arr[w][m]<<"."<<endl;
    }
}