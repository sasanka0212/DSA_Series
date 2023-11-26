#include <iostream>
using namespace std;

int sqrtNum(int n)
{
    int start = 0, end = n;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start < end)
    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

double precision(int n, int point, int integerPart)
{
    double fact = 0.1;
    double ans = integerPart;
    for (int i = 0; i < point; i++)
    {
        for (double j = ans; j * j < n; j += fact)
        {
            ans = j;
        }
        fact = fact / 10;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int intergerPart = sqrtNum(n);
    cout << "Square root of " << n << " is : " << intergerPart << endl;
    double ans = precision(n, 5, intergerPart);
    cout << "Actual square root is : " << ans;

    return 0;
}