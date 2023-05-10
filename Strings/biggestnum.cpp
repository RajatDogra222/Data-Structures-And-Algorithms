#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string str;
    cin>>str;

    // for(int i=0; i<str.size(); i++){
    //     for(int j=i+1; j<str.size(); j++){
    //         if(str[i] < str[j]){
    //            char temp=str[i];
    //            str[i]=str[j];
    //            str[j]=temp;
    //         }
    //     }
    // }

     sort(str.begin(),str.end(),greater<int>());

    cout<<str;
    return 0;
}