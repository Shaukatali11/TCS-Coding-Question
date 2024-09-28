#include<bits/stdc++.h>
using namespace std;

void reverseofstr(string str){
    int i=0;
    int j=str.size()-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
    cout<<str;
}

bool isPalandrome(string str){
    int i=0;
    int j=str.size()-1;
    
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void firstRepeatedChar(string str){
    int n=str.size();
    unordered_map<char,int>hmap;
    for(int i=0;i<n;i++){
        hmap[str[i]]++;
    }
    for(char c:str){
        if(hmap[c]>1){
            cout<<c;
            break;
        }
    }
}


void notRepeat(string str){
    int n=str.size();
    unordered_map<char,int>hmap;
    for(int i=0;i<n;i++){
        hmap[str[i]]++;
    }
    for(char c:str){
        if(hmap[c]==1){
            cout<<c;
        }
    }
}

bool nispanagram(string str){
    int alpha[26]={0};
    int n=str.size();
    for(int i=0;i<n;i++){
        alpha[str[i]]=1;
    }
    for(int i=0;i<26;i++){
        if(alpha[i]==0){
            return false;
        }
    }
    return true;
}
bool checkanagram(string str,string apr){
    if(str.size()!=apr.size()){
        return false;
    }
    sort(str.begin(),str.end());
    sort(apr.begin(),apr.end());
    return str==apr;
}
int main(){
    string str;
    cout<<"string 1 :";
    getline(cin,str);
  
    cout<<"reverse of string: ";
    reverseofstr(str);
  
    cout<<"\ncheck palindrom";
    cout<<isPalandrome(str);
  
    cout<<"\nfirst Repeating char of string: ";
    firstRepeatedChar(str);
  
    cout<<"\n Non repeated char of string : ";
    notRepeat(str);
  
    cout<<"\n ispanagram :";
    cout<<nispanagram(str);
  
    cout<<"string 2: ";
    string apr;
    getline(cin,apr);
  
    cout<<"is anagram : ";
    cout<<checkanagram(str,apr);
    return 0;
}
