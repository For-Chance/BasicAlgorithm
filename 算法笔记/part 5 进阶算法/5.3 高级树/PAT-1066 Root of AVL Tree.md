# 1066 Root of AVL Tree

> part 5, 5.1



## 题意理解

- 自平衡二叉搜索树(AVL)

### Sample Input 1:

```in
5
88 70 61 96 120
```

### Sample Output 1:

```out
70
```

### Sample Input 2:

```
7
88 70 61 96 120 90 65
```

### Sample Output 2:

```
88
```



## 自己解法

- 背模板吧，害

```c++
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
```



## 大神解法

- 柳神
- 写出建AVL（平衡二叉搜索树）的代码模版即可，rotateLeft表示左旋，rotateRight表示右旋，rotateLeftRight表示先左旋后右旋，rotateRightLeft表示先右旋后左旋，getHeight表示获取传入结点的子树的高度，insert表示插入建树的过程，如果root为空，直接新建结点插入即可～如果当前要插入的值小于root->val，则插入root的左子树；如果当前要插入的值大于root->val，则插入root的右子树～如果插入后左右子树高度差大于1，再根据值的大小比较进行旋转调整使树平衡～插入完成后返回root指针赋值给main函数里的root～最后输出root的val值～


```c++
#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node *rotateLeft(node *root) {
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node *rotateRight(node *root) {
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rotateLeftRight(node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
node *rotateRightLeft(node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node *root) {
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
    if(root == NULL) {
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
int main() {
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->val);
    return 0;
}
```

