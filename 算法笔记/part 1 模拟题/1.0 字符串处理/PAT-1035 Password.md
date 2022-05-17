# 1035 Password

> part 1, 1.0

## 自己解法

- 使用Account类，看起来比较麻烦，但是逻辑清晰

```c++
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
```



## 大神解法

- 柳神
- 将所有修改好的 name + password 放到 v 中，也很清晰

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string name, s;
        cin >> name >> s;
        int len = s.length(), flag = 0;
        for(int j = 0; j < len; j++) {
            switch(s[j]) {
                case '1' : s[j] = '@'; flag = 1; break;
                case '0' : s[j] = '%'; flag = 1; break;
                case 'l' : s[j] = 'L'; flag = 1; break;
                case 'O' : s[j] = 'o'; flag = 1; break;
            }
        }
        if(flag) {
            string temp = name + " " + s;
            v.push_back(temp);
        }
    }
    int cnt = v.size();
    if(cnt != 0) {
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++)
            cout << v[i] << endl;
    } else if(n == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", n);
    }
    return 0;
}
```



## 总结

- 注意有个 is 和 are 的区别，以及account单复数(OUTPUT2 和 OUTPUT3):joy::joy::joy::joy:
- string.find() 如果没找到，返回 string::npos