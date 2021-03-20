#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> stk;
    for (string token : tokens)
    {
        int a, b;
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();
        }
        if (token == "+")
        {
            stk.push(a + b);
        }
        else if (token == "-")
        {
            stk.push(a - b);
        }
        else if (token == "*")
        {
            stk.push(a * b);
        }
        else if (token == "/")
        {
            stk.push(a / b);
        }
        else
        {
            stk.push(stoi(token));
        }
    }
    return stk.top();
}