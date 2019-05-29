#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,t,n,p;
    vector<int> v;
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        for(i=0;i<n;i++){
            cin>>j;
            v.push_back(j);
        }
        sort(v.begin(),v.end());
        p=0;
        for(i=1;i<v.size();i++){
            if(i==n-1){
                if(1442-v[i]>100){
                    p=1;
                    break;
                }
            }else{
                if(v[i]-v[i-1]>200){
                    p=1;
                    break;
                }
                
            }
        }
        if(p){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<"POSSIBLE"<<endl;
        }
        v.clear();
    }
}