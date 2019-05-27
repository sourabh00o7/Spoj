#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int i,j,k,t;
    while(1){
        getline(cin,s);
        
        if(s[0]=='*'){
            break;
        }
        if(isupper(s[0])){
            t=s[0]-'A';
        }else{
            t=s[0]-'a';
        }
        k=0;
        for(i=2;i<s.length();i++){
            if(s[i-1]==' '){
                if(isupper(s[i])){
                    j=s[i]-'A';
                }else{
                    j=s[i]-'a';
                }
                if(j!=t){
                    k=1;
                    cout<<"N"<<endl;
                    break;
                }
            }
        }
        if(k==0){
            cout<<"Y"<<endl;
        }
    }
}