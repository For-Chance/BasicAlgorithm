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