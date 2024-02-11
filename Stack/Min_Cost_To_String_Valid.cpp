#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    if (str.length() % 2)
    {
        return -1;
    }
    stack<char> st;
    int a = 0, b = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
            b++;
        }
        else
        {
            if (st.empty() || st.top() == '}')
            {
                st.push(ch);
                a++;
            }
            else if (st.top() == '{')
            {
                st.pop();
                b--;
            }
        }
    }

    int change = (a + 1) / 2 + (b + 1) / 2;
    return change;
}

int main() {
    string str = "{{{}";
    cout << "Min cost to make string valid : " << findMinimumCost(str) << endl;
}