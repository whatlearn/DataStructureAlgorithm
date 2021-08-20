#include<iostream>
#include"AVLTree.h"

using namespace std;

int main()
{
    AVLTree<int> *tree = new AVLTree<int>();

    for(int i = 3; i > 0; i--)
    {
        tree->insert(i);
    }
    for(int i = 4; i < 8; i++)
    {
        tree->insert(i);
    }
    for(int i = 16; i > 9; i--)
    {
        tree->insert(i);
    }
    tree->insert(8);
    tree->insert(9);

    tree->preOrder();
    tree->inOrder();
    tree->postOrder();

    TreeNode<int> *node = tree->find(16);
    if(node != nullptr)
    {
        cout << node->value << endl;
    }

    delete tree;

    return 0;
}