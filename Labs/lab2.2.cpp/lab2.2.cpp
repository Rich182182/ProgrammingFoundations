#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

string infixToPostfix(const string &exp)
{
    stack<char> operators;
    stringstream postfix;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isspace(exp[i]))
            continue;

        if (isdigit(exp[i]))
        {
            while (i < exp.length() && (isdigit(exp[i]) || exp[i] == '.'))
            {
                postfix << exp[i];
                i++;
            }
            postfix << ' ';
            i--;
        }
        else
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(exp[i]))
            {
                postfix << operators.top() << ' ';
                operators.pop();
            }
            operators.push(exp[i]);
        }
    }

    while (!operators.empty())
    {
        postfix << operators.top() << ' ';
        operators.pop();
    }

    return postfix.str();
}

int evaluatePostfix(const string &postfix)
{
    stack<int> values;
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            values.push(stoi(token));
        }
        else
        {
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            values.push(applyOperation(val1, val2, token[0]));
        }
    }
    return values.top();
}

int main()
{
    string expression;
    cout << "Введіть арифметичний вираз: ";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);
    cout << "Постфіксна нотація: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Результат: " << result << endl;

    return 0;
}
