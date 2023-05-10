#include <bits/stdc++.h>
using namespace std;

char upper(char c){
    return 'A' + (c - 'a');
}
int main(){
    // string str;
    // getline(cin,str);

    // for(int i=0; i<str.size(); i++){
    //     if(str[i] != ' '){
    //        if(str[i]>='a' && str[i]<='z'){
    //           str[i]-=32;
    //           cout<<str[i];
    //        }
    //        else{
    //         cout<<str[i];
    //        }
    //     }
    //     else{
    //         cout<<endl;
    //     }
    // }
    
    while(true){
        string str;
        cin>>str;
        if(str.size()==0){
            break;
        }
        for(int i=0; i<str.size(); i++){
            str[i]=upper(str[i]);
        }
        cout<<str<<endl;
    }
    return 0;
}