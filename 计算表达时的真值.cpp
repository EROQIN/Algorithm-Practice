#include <bits/stdc++.h>
#include <pthread.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;++t){
        int n;
        cin >> n;
        unordered_map<char,char> map;
        for(int k=0;k<n;++k){
            pair<char,char> temp;
            cin >> temp.first >> temp.second;
            map.insert(temp);
        }
        string expr;
        cin >> expr;
        for(auto& i : expr){
            if(map.find(i)!=map.end()){
                i = map.find(i)->second;
            }
        }
        for(int i = 0;i<expr.size();++i){
            if(expr[i]=='!'){
                if(expr[i+1] == 'T') expr[i+1] = 'F';
                else expr[i+1] = 'T';
                expr.erase(i,1);--i;
                continue;
            }

            if(expr[i]=='&'){
                if(expr[i+1] == 'T' && expr[i-1] == 'T') expr[i-1] = 'T';
                else expr[i-1] = 'F';
                expr.erase(i,2);
                i-=2;
                continue;
            }
            if(expr[i]=='|'){
                if(expr[i+1] == 'F' && expr[i-1] == 'F') expr[i-1] = 'F';
                else expr[i-1] = 'T';
                expr.erase(i,2);i-=2;
                continue;
            }
            if(expr[i]=='>'){
                if(expr[i+1] == 'F' && expr[i-1] == 'T') expr[i-1] = 'F';
                else expr[i-1] = 'T';
                expr.erase(i,2);
                i-=2;
                continue;
            }
            if(expr[i]=='-'){
                if(expr[i+1] ==  expr[i-1]) expr[i-1] = 'T';
                else expr[i-1] = 'F';
                expr.erase(i,2);
                i-=2;
                continue;
            }
        }
        cout << expr << endl;
 
    }/*1
2
P F
Q T
!P-Q>P-Q*/
}