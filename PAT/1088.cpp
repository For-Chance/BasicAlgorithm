#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? abs(a) : gcd(b, a % b); }

void print(ll a, ll b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    ll maxg = gcd(a, b);
    a = a / maxg;
    b = b / maxg;
    ll x = a / b;
    if (x < 0)
        a = -a;
    a = a % b;
    if (a < 0 || x < 0)
        cout << '(';
    if (a == 0) // b = 1时a必为0
        cout << x;
    else if (a != 0 && x != 0)
        cout << x << ' ' << a << '/' << b;
    else
        cout << a << '/' << b;
    if (a < 0 || x < 0)
        cout << ')';
}

void sum(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " + ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * b2 + a2 * b1;
    b1 = b1 * b2;
    print(a1, b1);
    cout << endl;
}

void different(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " - ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * b2 - a2 * b1;
    b1 = b1 * b2;
    print(a1, b1);
    cout << endl;
}

void product(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " * ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * a2;
    b1 = b1 * b2;
    print(a1, b1);
    cout << endl;
}

void quotient(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " / ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * b2;
    b1 = a2 * b1;
    if (b1 == 0)
        cout << "Inf";
    else
        print(a1, b1);
    cout << endl;
}

int main()
{
    ll a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    sum(a1, b1, a2, b2);
    different(a1, b1, a2, b2);
    product(a1, b1, a2, b2);
    quotient(a1, b1, a2, b2);
    system("pause");
    return 0;
}