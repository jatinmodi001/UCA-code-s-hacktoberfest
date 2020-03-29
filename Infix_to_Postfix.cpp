# Question : https://practice.geeksforgeeks.org/problems/infix-to-postfix/0

#include <iostream>
#include<stack>
using namespace std;

bool isOperand (char ch)
{
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

int prec(char ch)
{
    if(ch == '^')
        return 4;
    else if(ch == '*' || ch =='/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        string ans;
        stack<char> st;
        for(int i=0;i<str.length();i++)
        {
            if(isOperand(str[i]))
            {
                ans = ans + str[i];
                continue;
            }
            
            if(str[i] == '(')
                st.push(str[i]);
            else if(str[i] == ')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                if(st.top() == '(')
                    st.pop();
            }
            else{
                
                while(!st.empty() && prec(st.top()) >= prec(str[i]))
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        while(!st.empty())
        {
            ans = ans+st.top();
            st.pop();        }
        cout<<ans<<endl;
    }
	//code
	return 0;
}
