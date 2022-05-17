#include <iostream>
using namespace std;
struct node
{
    int val;
    struct node *left, *right;
};

node *rotateLeft(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node *rotateRight(node *root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node *rotateLeftRight(node *root)
{
    // 这里一定一定要注意 temp 的 left 和 right 的分配，下个函数同理
    // 下面这样写会出现段错误
    // node *temp = root->left->right;
    // temp->left = root->left;
    // temp->right = root;
    // root->left->right = temp->left;
    // root->left = temp->right;
    // return temp;
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

node *rotateRightLeft(node *root)
{
    // node *temp = root->right->left;
    // temp->left = root;
    // temp->right = root->right;
    // root->right->left = temp->right;
    // root->right = temp->left;
    // return temp;
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getMaxHeight(node *root)
{
    if (root == NULL)
        return 0;
    return max(getMaxHeight(root->left), getMaxHeight(root->right)) + 1;
}

node *insert(node *root, int nowVal)
{
    if (root == NULL)
    {
        // 如果root是NULL，返回一个新的node节点
        root = new node();
        root->val = nowVal;
        root->left = NULL;
        root->right = NULL;
    }
    else if (nowVal < root->val)
    {
        root->left = insert(root->left, nowVal);
        // 这里注意只有当 左右子树 高度不等的时候才会更新 root
        if (getMaxHeight(root->left) - getMaxHeight(root->right) == 2)
            root = (nowVal < root->left->val) ? rotateRight(root) : rotateLeftRight(root);
    }
    else
    {
        root->right = insert(root->right, nowVal);
        if (getMaxHeight(root->right) - getMaxHeight(root->left) == 2)
            root = (nowVal > root->right->val) ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root; // 返回是 root
}

int main()
{
    int N;
    cin >> N;
    struct node *root = NULL;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        root = insert(root, a);
    }
    cout << root->val << endl;
    system("pause");
    return 0;
}