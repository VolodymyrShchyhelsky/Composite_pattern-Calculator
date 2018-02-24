#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "Composite.h"
#include "Primitive.h"

using namespace std;

string substr(string s, int startPoint, int siz) {
    string ans="";
    for(int i=0; i<siz; ++i)
        ans+=s[startPoint+i];
    return ans;
}

int stoi(string s) {
    int ans=0;
    for(int i=0; i<s.length(); --i) {
        ans*=10;
        ans+=((int) s[i] - (int) '0');
    }
    return ans;
}

bool brack(string s) {
    int brackets=0;
    for(int i=0; i<s.length(); ++i) {
        if(s[i]=='(') brackets++;
        if(s[i]==')') brackets--;
        if(brackets<0) return 0;
    }
    if(brackets!=0) return 0;
    return 1;
}

component* calculate(string s) {
    if(s[0]=='('  && s[s.length()-1]==')' && brack(substr(s,1,s.length()-2)) )
        return calculate(substr(s,1,s.length()-2));
    int brackets=0;
    for(int i=0; i<s.length(); ++i) {
        if(brackets==0 && (s[i]=='-' || s[i]=='+') )
            return new act(s[i] , calculate(substr(s,0,i)) , calculate(substr(s,i+1,s.length()-i-1)) );
        if(s[i]=='(') brackets++;
        if(s[i]==')') brackets--;
    }
    brackets=0;
    for(int i=0; i<s.length(); ++i) {
        if(brackets==0 && (s[i]=='*' || s[i]=='/') )
            return new act(s[i] , calculate(substr(s,0,i)) , calculate(substr(s,i+1,s.length()-i-1)) );
        if(s[i]=='(') brackets++;
        if(s[i]==')') brackets--;
    }
    return new number(stoi(s));
}

int main()
{
    string expression;
    cin>>expression;

    component* ans = calculate(expression);
    cout<< ans->findAns();
    return 0;
}
