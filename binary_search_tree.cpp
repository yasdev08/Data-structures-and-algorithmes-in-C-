#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left, *right;
};

void insert(node *&root, int val)
{
    node *p = root, *prev = NULL;
    while (p != NULL)
    {
        prev = p;
        if (p->data > val)
            p = p->left;
        else
            p = p->right;
    }
    node *nouv = new node;
    nouv->data = val;
    nouv->right = nouv->left = NULL;
    if (prev == NULL)
        root = nouv;
    else if (prev->data > val)
        prev->left = nouv;
    else
        prev->right = nouv;
}
void inorder(node *root) // left - root - right
{
    node *p = root;
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void preorder(node *root) // root , left ,right
{
    node *p = root;
    if (p != NULL)
    {

        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *root) // left, right , root
{
    node *p = root;
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}
int main()
{
    int val;
    node *root = NULL;
    cout << "Insert elements into the binary tree : (0 to quit inserting ) " << endl;
    do
    {
        cin >> val;
        insert(root, val);
    } while (val != 0);
    cout << "the binary tree inorder : ";
    inorder(root);
    cout << endl;
    cout << "the binary tree preorder : ";
    preorder(root);
    cout << endl;
    cout << "the binary tree postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}