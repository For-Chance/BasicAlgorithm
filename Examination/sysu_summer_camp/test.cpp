#include <iostream>
using namespace std;

class base
{
public:
    base() { cout << "Constructing base\n"; }
    virtual void isa() { cout << "base\n"; }
    ~base() { cout << "Constructing base\n"; }
};

class clique : public base
{
public:
    void isa()
    {
        cout << "clique" << endl;
    }
};

class derive : public base
{
public:
    void isa()
    {
        cout << "derive" << endl;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    base *p, b;
    clique c;
    derive d;
    b.isa();
    c.isa();
    d.isa();
    p = &b;
    p->isa();
    p = &c;
    p->isa();
    p = &d;
    p->isa();
    return 0;
}