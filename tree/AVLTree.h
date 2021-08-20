#ifndef _AVLTREE_H
#define _AVLTREE_H

#include <algorithm>

template <typename T>
struct TreeNode
{
    T value;
    TreeNode *leftTree;
    TreeNode *rightTree;
    short height;
};

template <typename T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void insert(const T newVal);
    void remove(const T val);
    TreeNode<T> *find(const T val);
    const T findMin();
    const T findMax();

    void preOrder();
    void inOrder();
    void postOrder();

    void showRoot();

private:
    TreeNode<T> *insert(TreeNode<T> *node, const T val);
    TreeNode<T> *find(TreeNode<T> *node, const T val);
    TreeNode<T> *findMin(TreeNode<T> *node);
    TreeNode<T> *findMax(TreeNode<T> *node);

    void preOrder(TreeNode<T> *node);
    void inOrder(TreeNode<T> *node);
    void postOrder(TreeNode<T> *node);

    short height(TreeNode<T> *node);

    TreeNode<T> *LLrotation(TreeNode<T> *node);
    TreeNode<T> *RRrotation(TreeNode<T> *node);
    TreeNode<T> *LRrotation(TreeNode<T> *node);
    TreeNode<T> *RLrotation(TreeNode<T> *node);

private:
    TreeNode<T> *root;
};

template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

//implement
template <typename T>
AVLTree<T>::~AVLTree()
{
}

template <typename T>
void AVLTree<T>::insert(const T newVal)
{
    root = insert(root, newVal);
}

template <typename T>
void AVLTree<T>::remove(const T newVal)
{
}

template <typename T>
TreeNode<T> *AVLTree<T>::find(const T val)
{
    return find(root, val);
}

template <typename T>
const T AVLTree<T>::findMin()
{
    TreeNode<T> *minLeaf = findMin(root);
    return minLeaf->value;
}

template <typename T>
const T AVLTree<T>::findMax()
{
    TreeNode<T> *maxLeaf = findMax(root);
    return maxLeaf->value;
}

template <typename T>
void AVLTree<T>::preOrder()
{
    preOrder(root);
    printf("\n");
}

template <typename T>
void AVLTree<T>::inOrder()
{
    inOrder(root);
    printf("\n");
}

template <typename T>
void AVLTree<T>::postOrder()
{
    postOrder(root);
    printf("\n");
}

template <typename T>
TreeNode<T> *AVLTree<T>::insert(TreeNode<T> *node, const T val)
{
    if (node == nullptr)
    {
        node = new TreeNode<T>();
        node->value = val;
        node->leftTree = node->rightTree = nullptr;
        node->height = 0;
    }
    else
    {
        if (node->value > val)
        {
            node->leftTree = insert(node->leftTree, val);
            if (std::abs(height(node->leftTree) - height(node->rightTree)) == 2)
            {
                if (node->leftTree->value > val)
                {
                    node = LLrotation(node);
                }
                else
                {
                    node = LRrotation(node);
                }
            }
        }
        else if (node->value < val)
        {
            node->rightTree = insert(node->rightTree, val);
            if (abs(height(node->rightTree) - height(node->leftTree)) == 2)
            {
                if (node->rightTree->value < val)
                {
                    node = RRrotation(node);
                }
                else
                {
                    node = RLrotation(node);
                }
            }
        }
    }

    return node;
}

template <typename T>
TreeNode<T> *AVLTree<T>::find(TreeNode<T> *node, const T val)
{
    if (node == nullptr)
    {
        return node;
    }
    if (node->value > val)
    {
        node = find(node->leftTree, val);
    }
    else if (node->value < val)
    {
        node = find(node->rightTree, val);
    }
    return node;
}

template <typename T>
TreeNode<T> *AVLTree<T>::findMin(TreeNode<T> *node)
{
    if (node->leftTree == nullptr)
    {
        return node;
    }
    else
    {
        findMin(node->leftTree);
    }
}

template <typename T>
TreeNode<T> *AVLTree<T>::findMax(TreeNode<T> *node)
{
    if (node->rightTree == nullptr)
    {
        return node;
    }
    else
    {
        findMax(node->rightTree);
    }
}

template <typename T>
void AVLTree<T>::preOrder(TreeNode<T> *node)
{
    printf("%d ", node->value);
    // printf("%d ", node->height);
    if (node->leftTree != nullptr)
    {
        preOrder(node->leftTree);
    }
    if (node->rightTree != nullptr)
    {
        preOrder(node->rightTree);
    }
}

template <typename T>
void AVLTree<T>::inOrder(TreeNode<T> *node)
{
    if (node->leftTree != nullptr)
    {
        inOrder(node->leftTree);
    }
    printf("%d ", node->value);
    if (node->rightTree != nullptr)
    {
        inOrder(node->rightTree);
    }
}

template <typename T>
void AVLTree<T>::postOrder(TreeNode<T> *node)
{
    if (node->leftTree != nullptr)
    {
        postOrder(node->leftTree);
    }
    if (node->rightTree != nullptr)
    {
        postOrder(node->rightTree);
    }
    printf("%d ", node->value);
}

template <typename T>
short AVLTree<T>::height(TreeNode<T> *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        node->height = std::max(height(node->leftTree), height(node->rightTree)) + 1;
        return node->height;
    }
}

template <typename T>
TreeNode<T> *AVLTree<T>::LLrotation(TreeNode<T> *node)
{
    TreeNode<T> *curNode = node->leftTree;
    node->leftTree = curNode->rightTree;
    curNode->rightTree = node;
    return curNode;
}

template <typename T>
TreeNode<T> *AVLTree<T>::RRrotation(TreeNode<T> *node)
{
    TreeNode<T> *curNode = node->rightTree;
    node->rightTree = curNode->leftTree;
    curNode->leftTree = node;
    return curNode;
}

template <typename T>
TreeNode<T> *AVLTree<T>::LRrotation(TreeNode<T> *node)
{
    node->leftTree = RRrotation(node->leftTree);
    return LLrotation(node);
}

template <typename T>
TreeNode<T> *AVLTree<T>::RLrotation(TreeNode<T> *node)
{
    node->rightTree = LLrotation(node->rightTree);
    return RRrotation(node);
}

template <typename T>
void AVLTree<T>::showRoot()
{
    printf("%d\n", root->value);
}
#endif