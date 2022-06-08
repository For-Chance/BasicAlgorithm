#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 26;
    unordered_map<int, vector<string>> alpha;
    for (int i = 0; i < N; i++)
    {
        vector<string> m(7);
        for (int j = 0; j < 7; j++)
            cin >> m[j];
        alpha[i] = m;
    }
    string sentence;
    cin.ignore();
    getline(cin, sentence);
    vector<string> words;
    for (int i = 0; i < sentence.length();)
    {
        while (sentence[i] - 'A' < 0 || sentence[i] - 'A' >= 26)
        {
            i++;
        }
        int start = i;
        while (sentence[i] - 'A' >= 0 && sentence[i] - 'A' < 26)
        {
            i++;
        }
        words.push_back(sentence.substr(start, i - start));
        while (sentence[i] - 'A' < 0 || sentence[i] - 'A' >= 26)
        {
            i++;
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        vector<vector<string>> show(7, vector<string>(words[i].length()));
        for (int j = 0; j < words[i].length(); j++)
            for (int k = 0; k < 7; k++)
                show[k][j] = alpha[int(words[i][j] - 'A')][k];
        for (int j = 0; j < show.size(); j++)
        {
            cout << show[j][0];
            for (int k = 1; k < show[j].size(); k++)
                cout << " " << show[j][k];
            cout << endl;
        }
        if (i != words.size() - 1)
            cout << endl;
    }
    system("pause");
    return 0;
}