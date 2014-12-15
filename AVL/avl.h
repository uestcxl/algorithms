#ifndef AVL_H_
#define AVL_H_

//定义avl的结构以及相关操作
#include "stdio.h"
#include "stdlib.h"

struct AVLTree{
    unsigned int nData;
    struct AVLTree* pLeft;  //左子树
    struct AVLTree* pright; //右子树
    int nHeight;            //结点平衡度
};

//插入操作
struct AVLTree* insert_tree(unsigned int nData,struct AVLTree* pNode);

//查找操作，找到则返回1，否则返回0
int find_tree(unsigned int nData,struct AVLTree* pRoot);

//删除树
void delete_tree(struct AVLTree** ppRoot);

//打印树
void print_tree(struct AVLTree* pRoot);

#endif
