#include <iostream>
using namespace std;

// Recursive function
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;

    cout << "Enter the term position: ";
    cin >> n;

    cout << "The " << n << "th Fibonacci term is: "
         << fibonacci(n);

    return 0;
}