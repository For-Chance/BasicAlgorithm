#include <iostream>
using namespace std;
#include <map>

int main()
{
    int M, N;
    cin >> M >> N;
    map<int, int> m;
    int half = M * N / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            m[x]++;
            if (m[x] > half)
            {
                cout << m[x] << endl;
                return 0;
            }
        }
    system("pause");
    return 0;
}