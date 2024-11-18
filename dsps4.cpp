/dsps 4 infix to post fix/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
 int precedence(char c){
 if(c=='+'||c=='-')
 {
 return 1;
 }
 else if(c=='/'||c=='*')
 {
 return 2;
 }
 else if(c=='^')
 {
 return 3;
 }
 return 0;
 
 }
 
 bool isOperator(char c)
 {
 return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
 }
 
 string infixtopostfix(string infix)
 {
 stack<char>s;
 string postfix="";
 
 for(int i=0;i<infix.length();i++)
 {
 char c=infix[i];
 if(isalnum(c))
{
postfix+=c;
} 

else if(c=='(')
{
s.push(c);
}
else if(c==')')
{
while(!s.empty && s.top()!='(')
{
postfix+=s.top();
s.pop();
}
s.pop();
}
else if(isOperator(c))
{
while(!s.empty() &&  precedence(s.top())>=precedence(c))
{
postfix +=s.top;
s.top();
}
s.push(c);
}
 }
 while(!s.empty())
 {
 postfix +=s.top;
 s.pop();
 }
 return postfix;
 }
 
 int main()
 {
 string infix;
 cout<<"enter an infix expression:";
 cin>>infix;
 
 string postfix=infixtopostfix(infix);
 cout<<"postfix expression:"<<postfix<<endl;
 return 0;
 }