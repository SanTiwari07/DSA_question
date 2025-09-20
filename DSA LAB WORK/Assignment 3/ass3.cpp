#include <iostream>
#include <stack>
using namespace std;

int operations(int num1, int num2, char op)
{
    if (op == '+')
        return num1 + num2;
    if (op == '-')
        return num1 - num2;
    if (op == '*')
        return num1 * num2;
    if (op == '/')
        return num1 / num2;
    return 0;
}

int prior(char op)
{
    if (op == '+' || op == '-')
        return 10;
    if (op == '*' || op == '/')
        return 200;
    return 0;
}

int calculate(string input)
{
    stack<int> values;
    stack<char> ops;

    for (int a = 0; a < input.size(); a++)
    {
        if (input[a] == ' ')
            continue;

        else if (isdigit(input[a]))
        {
            int value = 0;
            while (a < input.length() && isdigit(input[a]))
            {
                value = 10 * value + (input[a] - '0');
                a++;
            }
            values.push(value);
            a--;
        }

        else if (input[a] == '(')
        {
            ops.push(input[a]);
        }

        else if (input[a] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(operations(a, b, op));
            }
            ops.pop();
        }
        else
        { 
            while (!ops.empty() && prior(ops.top()) >= prior(input[a]))
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(operations(a, b, op));
            }
            ops.push(input[a]);
        }
    }

    while (!ops.empty())
    {
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(operations(a, b, op));
    }

    return values.top();
}

int main()
{
    string input;
    cout << "Enter expression: ";
    getline(cin, input);
    cout << "Result: " << calculate(input) << endl;
}
