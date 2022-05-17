# 1022 Digital Library

> part 4, 4.0



## 自己解法

- 用结构去找的话很慢很慢且很麻烦

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct book
{
    int ID, pu_year;
    string book_title, author, key_words[5], publisher;
};

bool cmp(book a, book b)
{
    return a.ID < b.ID;
}

int main()
{
    int N;
    cin >> N;
    vector<book> b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> b[i].ID;
        getline(cin, b[i].book_title);
        getline(cin, b[i].author);
        for (int j = 0; cin >> b[i].key_words[j]; j++)
            ;
        getline(cin, b[i].publisher);
        cin >> b[i].pu_year;
    }
    sort(b.begin(), b.end(), cmp);
    int M;
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d: ", &i);
        string search;
        getline(cin, search);
    }
    system("pause");
    return 0;
}
```

- 重新写
- ==用set存储ID==，别用int，==赋值不要insert，而是方括号==

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
map<string, int> mapbook, mapauthor, mappublisher;
map<int, int> mapyear;
map<vector<string>, int> mapkeywords;

int main()
{
    int N;
    cin >> N;
    int ID, year;
    string booktitle, author, publisher;
    vector<string> keywords;
    for (int i = 0; i < N; i++)
    {
        cin >> ID;
        getchar();
        getline(cin, booktitle);
        getline(cin, author);
        string s;
        while (cin >> s)
        {
            keywords.push_back(s);
        }
        getchar();
        getline(cin, publisher);
        cin >> year;
        getchar();
        mapbook.insert(make_pair(booktitle, ID));
        mapauthor.insert(make_pair(author, ID));
        mapkeywords.insert(make_pair(keywords, ID));
        mappublisher.insert(make_pair(publisher, ID));
        mapyear.insert(make_pair(year, ID));
    }
    int M;
    cin >> M;
    int index;
    string search;
    for (int i = 0; i < M; i++)
    {
        scanf("%d: ", &index);
        getline(cin, search);
    }
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map<string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(auto it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
    int n, m, id, num;
    scanf("%d", &n);
    string ttitle, tauthor, tkey, tpub, tyear;
    for(int i = 0; i < n; i++) {
        scanf("%d\n", &id);
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin >> tkey) {
            key[tkey].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub,temp);
        else if(num ==5) query(year, temp);
    }
    return 0;
}
```

