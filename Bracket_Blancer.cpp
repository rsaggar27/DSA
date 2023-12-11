#include <iostream>
#include<stack>
using namespace std;

bool bracketBlancer(string exp)
{
    stack<char>stk;
    for(int i=0;i<exp.size();i++)
    {
        char ch=exp[i];

        if(ch=='{'|| ch=='('||ch=='[')
        {
            stk.push(ch);
        }
        else
        {
            char br=stk.top(); 

            if(br=='('&& ch==')'||br=='{'&& ch=='}'||br=='['&& ch==']')
            stk.pop();
            else
            return false;
        }
    }

    if(stk.empty())
    return true;

    else
    return false;

}

int main()
{
    string exp= "{[()]}";

    bool resp= bracketBlancer(exp);
    
    if(resp==false)
    cout<<"\n*********** Brackets not Balanced *************\n";
    else
    cout<<"\n**************** Bracket Balanced ****************\n";

}

