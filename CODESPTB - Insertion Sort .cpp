#include<bits/stdc++.h>
using namespace std;
int t,a[100000];
void merge(int r,int b,int c, int d){
    int i,j,k;
   
    int p[b-r+1],q[d-c+1];
    for(i=r;i<=b;i++){
        p[i-r]=a[i];
    }
    for(i=c;i<=d;i++){
        q[i-c]=a[i];
    }
    i=0;
    j=0;
    k=r;
    while(i<b-r+1&&j<d-c+1){
        if(q[j]<p[i]){
            a[k]=q[j];
            k++;
            j++;
            t=t+b-r-i+1;
        }else{
            a[k]=p[i];
            k++;
            i++;
        }
    }
    while(i<b-r+1){
        a[k]=p[i];
        k++;
        i++;
    }
    while(j<d-c+1){
        a[k]=q[j];
        k++;
        j++;
    }
    
}
void ms(int w,int b){
    if(w==b){
        return ;
    }else{
        int mid=w+b;
        mid=mid/2;
        ms(w,mid);
        ms(mid+1,b);
        merge(w,mid,mid+1,b);
    }
}
int main(){
    int i,j,k,e,n;
    cin>>e;
    for(i=0;i<e;i++){
        cin>>n;
        t=0;
        for(j=0;j<n;j++){
            cin>>a[j];
        }
        ms(0,n-1);
        cout<<t<<endl;
    }
}