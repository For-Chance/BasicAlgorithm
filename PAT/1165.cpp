#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value, next;
    int rank;
    bool flag = false;
};

class Solution
{
public:
    int finalRoot;
    int adjust(unordered_map<int, node> &map, int root, int block)
    {
        int newRoot = dfs_block(map, root, block);
        map[newRoot].next = -1;
        return finalRoot;
    }

    int dfs_block(unordered_map<int, node> &map, int root, int &block)
    {

        int cnt = 0;
        int startNode = root, endNode;
        while (cnt != block - 1 && map[root].next != -1)
        {
            root = map[root].next;
            cnt++;
        }
        endNode = root;
        if (map[root].next == -1)
        {
            finalRoot = startNode;
            return endNode;
        }
        int newRoot = dfs_block(map, map[root].next, block);
        map[newRoot].next = startNode;
        return endNode;
    }
};

int main()
{
    int root, N, K;
    cin >> root >> N >> K;
    unordered_map<int, node> map;
    for (int i = 0; i < N; i++)
    {
        int add, value, next;
        cin >> add >> value >> next;
        node x;
        x.value = value;
        x.next = next;
        map[add] = x;
    }
    int rank = 1;
    int root_cp = root;
    while (root_cp != -1)
    {
        map[root_cp].rank = rank;
        map[root_cp].flag = true;
        root_cp = map[root_cp].next;
        rank++;
    }
    Solution solution;
    int nowRoot = solution.adjust(map, root, K);
    while (nowRoot != -1)
    {
        if (map[nowRoot].next != -1)
            printf("%05d %d %05d\n", nowRoot, map[nowRoot].value, map[nowRoot].next);
        else
            printf("%05d %d -1\n", nowRoot, map[nowRoot].value);
        nowRoot = map[nowRoot].next;
    }
    system("pause");
    return 0;
}