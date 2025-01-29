// Tricky Solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int sToi(string node){
    int value=0;
    for(int i=node.size()-1,mul=1;i>=0;i--,mul*=10){
        value+=(node[i]-'0')*mul;
    }
    return value;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int k;
    string s;
    vector<vector<int>>v(10);
    cin>>k>>s;
    int count=-1;
    string node;
    for(int i=0;i<int(s.size());i++){
        if('0'<=s[i] && s[i]<='9'){
            node+=s[i];
        }
        else{
            if(!node.empty()){
                int value=sToi(node);
                v[count].push_back(value);
            }
            node.clear();
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
        }
    }
    int sum=0;
    for(int i=0;i<int(v[k].size());i++){
        sum+=v[k][i];
    }
    cout<<sum<<endl;
    return 0;
}
