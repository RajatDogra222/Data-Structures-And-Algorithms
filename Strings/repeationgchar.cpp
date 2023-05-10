#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    int freq[26];

    for(int i=0; i<26; i++){
        freq[i]=0;
    }

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }

    char ans='a';
    int maxf=0;

    for(int i=0; i<26; i++){
        if(freq[i] > maxf){
            ans=i+'a';
            maxf=freq[i];
       }
    }

    cout<<ans<<" "<<maxf;
    return 0;
}