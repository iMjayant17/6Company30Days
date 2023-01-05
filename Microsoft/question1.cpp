// Q1) https://leetcode.com/problems/evaluate-reverse-polish-notation/

// LeetCode Submission : https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/871184081/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int evalRPN(vector<string> &tokens)
{
    stack<string> s;
    for (auto token : tokens)
    {
        // first we are checking if the current token is an operand or not
        // if it isnt then just push it to the stack else
        // we get the numbers on top , evaluate them and store the result in the stack again
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int b = stoi(s.top()); // b first
            s.pop();
            int a = stoi(s.top()); // a second
            s.pop();
            s.push(
                to_string(token == "+" ? a + b : token == "-" ? a - b
                                             : token == "*"   ? a * b
                                                              : a / b)); // pushing the result into stack
        }
        else
        {
            s.push(token);
        }
    }
    return stoi(s.top()); // top will be the result of whole postfix
}

int main()
{
    vector<string> a = {"2",
                        "1",
                        "+",
                        "3",
                        "*"};
    vector<string> b = {"4", "13", "5", "/", "+"};
    vector<string> c = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(a) << endl;
    cout << evalRPN(b) << endl;
    cout << evalRPN(c) << endl;
    return 0;
}