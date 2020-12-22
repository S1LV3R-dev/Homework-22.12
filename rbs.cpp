#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    stack <int> p;
    string s;
    ifstream fin(argv[1]);
    if (!fin.is_open()){
    	cout << "Can't open this file\n";
    	return 1;
    }
    else{
        string str;
        while(getline(fin,str)){
            s+=str;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='(' || s[i] == '{' || s[i] == '['){
            p.push(s[i]);
        }
        else{
            if(s[i] == ')' && !p.empty() && p.top() == '(') {
                p.pop();
            }
            else if (s[i] == '}' && !p.empty() && p.top() == '{') {
                p.pop();
            }
            else if (s[i] == ']' && !p.empty() && p.top() == '[') {
                p.pop();
            }
            else if ((s[i] == '}' || s[i] == ')' || s[i]==']') && p.empty()) {
                p.push(i);
                break;
            }
        }
    }
    if(p.empty()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
