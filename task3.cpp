#include<iostream>
using namespace std;
class Stack{
	int top;
	public:
		char a[21];
	Stack(){
		top=-1;
	}
    bool push(char x){
		if(top>=20){
			cout<<"Stack overflow\n";
			return false;
		}
		else{
			a[++top]=x;
			cout<<"Pushed "<<x<<" into stack "<<endl;
			return true;
		}
	}
	char pop(){
		if(top<0){
			cout<<"Stack underflow\n";
			return false;
		}
		else{
			char x=a[top--];
			return x;
		}
	}
	char peek(){
		if(top<0){
			//cout<<"Stack is empty\n";
			return 0;
		}
		else{
			char x=a[top];
			return x;
		}
	}
	bool isEmpty()
    {
	   return(top<0);
    }
	
};

int prec(char c)
{
		if(c == '^')
		  return 3;
		else if(c == '*' || c == '/')
		  return 2;
		else if(c == '+' || c == '-' )
		   return 1;
		else
		  return -1;
}
string fix(string infix){
		Stack obj;
	    string postfix;
	    for(int i=0;i<infix.length();i++)
		{
		     if( (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
	        {
	            postfix = postfix + infix[i]; 
	        }
	        else if(infix[i]=='(')
	        {
	            obj.push(infix[i]);
	        }
	        else if(infix[i]==')')
	        {
	            while(!obj.isEmpty() && obj.peek() != '(')
	            {
	                postfix = postfix + obj.peek();
	                obj.pop();
	            }
	            if(!obj.isEmpty())
	            {
	                obj.pop();
	            }
	        }
	        else
	        {
	            while(!obj.isEmpty() && prec(obj.peek()) > prec(infix[i]))
	            {
	                postfix = postfix + obj.peek();
	                obj.pop();
	            }
	            obj.push(infix[i]);
	        }
		}
		while(!obj.isEmpty()){
			postfix=postfix+obj.peek();
			obj.pop();
		}
        return postfix;
} 
int main()
{
	string infix="a+b*(c^d-e)^(f+g*h)-i";
	cout<<infix<<endl;
	string postfix=fix(infix);
    cout<<endl<<postfix<<" ";
	return 0;
}
