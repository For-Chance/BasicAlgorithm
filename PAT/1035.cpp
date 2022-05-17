#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Account
{
public:
    string username;
    string password;

    Account(string username, string password)
    {
        this->username = username;
        for (int i = 0; i < password.length(); i++)
        {
            switch (password[i])
            {
            case '1':
                password[i] = '@';
                break;
            case '0':
                password[i] = '%';
                break;
            case 'l':
                password[i] = 'L';
                break;
            case 'O':
                password[i] = 'o';
                break;
            }
        }
        this->password = password;
    }
};

class printModified
{
public:
    void operator()(Account a)
    {
        cout << a.username << " " << a.password << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    int m = n, temp = n;
    vector<Account> v;
    while (n--)
    {
        string username;
        string password;
        cin >> username >> password;
        if (password.find("1") != string::npos || password.find("0") != string::npos || password.find("l") != string::npos || password.find("O") != string::npos)
        {
            Account a(username, password);
            v.push_back(a);
            m--;
        }
    }
    if (m == temp)
    {
        if (temp == 1)
            cout << "There is " << m << " account and no account is modified" << endl;
        else
            cout << "There are " << m << " accounts and no account is modified" << endl;
    }
    else
    {
        cout << temp - m << endl;
        for_each(v.begin(), v.end(), printModified());
    }

    system("pause");
    return 0;
}
