#include "avl.h"
#include "utl.h"

//返回两者较大值
static int Max(int a , int b);

//返回当前结点的平衡度
static int Height(struct AVLTree* pNode);

//旋转操作
static struct AVLTree* SingleRotateWithLeft(struct AVLTree* pNode);
static struct AVLTree* SingleRotateWithRight(struct AVLTree* pNode);
static struct AVLTree* DoubleRotateWhtiLeft(struct AVLTree* pNode);
static struct AVLTree* DoubleRotateWhtiRight(struct AVLTree* pNode);

//开始函数实现

/*
 *  插入
 *      参数：nData:待插入的值，pNode:某个结点(第一次调用时为根结点)
 * */
struct AVLTree* insert_tree(unsigned int nData , struct AVLTree* pNode){
    if(pNode==NULL){
        pNode=(struct AVLTree*)xalloc(sizeof(struct AVLTree));
        pNode->nData=nData;
        pNode->nHeight=0;
        pNode->pLeft=pNode->pright=NULL;;
    }
    //待插入值小于当前结点值，递归插入左子树中
    else if(pNode->nData > nData){
       pNode->pLeft=insert_tree(nData,pNode->pLeft);
       //检测平衡性
       if(Height(pNode->pLeft)-Height(pNode->pright) ==2 ){
            if(nData < pNode->pLeft->nData){
                //若插入到了左子树的左边，则采用简单的左旋操作
                pNode=SingleRotateWithLeft(pNode);
            }
            else{
                //若插入到左子树的右边，则采用左子树双旋转
                pNode=DoubleRotateWhtiLeft(pNode);
            }
       }
    }
    else if(nData > pNode->nData){
        pNode->pright=insert_tree(nData,pNode->pright);
        if(Height(pNode->pright)-Height(pNode->pLeft) ==2){
            if(nData < pNode->pright->nData){
                //若插入到了右子树的右边，则采用简单的右旋操作
                pNode=SingleRotateWithRight(pNode);
            }
            else{
                //若插入到了右子树的左边，则采取右子树双旋
                pNode=DoubleRotateWhtiRight(pNode);
            }
        }
    }

    pNode->nHeight=Max(Height(pNode->pLeft),Height(pNode->pright))+1;

    return pNode;
}

/*
 *  删除树：
 *      参数：指向根结点的指针
 *
 * */

void delete_tree(struct AVLTree** ppRoot){
    if(ppRoot==NULL || *ppRoot==NULL){
        return;
    }
    delete_tree(&((*ppRoot)->pLeft));
    delete_tree(&((*ppRoot)->pright));
    xfree(*ppRoot);
    *ppRoot=NULL;
    return;
}

/*
 *  中序遍历平衡二叉排序树，结果为从小到大
 *
 * */
void print_tree(struct AVLTree* pRoot){
    if(pRoot==NULL){
        return;
    }
    print_tree(pRoot->pLeft);
    printf("Data=%d\n",pRoot->nData);
    print_tree(pRoot->pright);
}

/*
 *  查找操作
 *
 * */
int find_tree(unsigned int nData,struct AVLTree* pRoot){
    static int k=1;     //统计查找次数
    if(pRoot==NULL){
        printf("data %d can not be found ! Search time %d",nData,k);
        return 0;
    }
    if(nData==pRoot->nData){
        printf("Find it ! Search time %d\n",k);
        return 1;
    }
    //否则递归查找左子树
    else if(nData < pRoot->nData){
        k++;
        return find_tree(nData,pRoot->pLeft);
    }
    //递归查找右子树
    else if(nData > pRoot->nData){
        k++;
        return find_tree(nData,pRoot->pright);
    }
}

/*
 *   返回两者中较大值
 * */
static int Max(int a , int b){
    return ( a > b ? a : b);
}

/*
 *  返回当前结点的平衡度
 * */
static int Height(struct AVLTree* pRoot){
    if(pRoot==NULL){
        return -1;
    }
    return pRoot->nHeight;
}

/*
 *  简单的左旋操作
 *      基本思想：将该结点的左结点作为该结点，该结点作为右结点，左结点的左结点作为左结点
 * */
static struct AVLTree* SingleRotateWithLeft(struct AVLTree* pNode){
    struct AVLTree* tmpNode;
    tmpNode=pNode->pLeft;
    pNode->pLeft=tmpNode->pright;
    tmpNode->pright=pNode;

    //更新平衡度
    pNode->nHeight=Max(Height(pNode->pLeft),Height(pNode->pright))+1;
    tmpNode->nHeight=Max(Height(tmpNode->pLeft),Height(tmpNode->pright))+1;

    return tmpNode;
}

/*
 *  简单的右旋操作
 * */
static struct AVLTree* SingleRotateWithRight(struct AVLTree* pNode){
    struct AVLTree* tmpNode;
    tmpNode=pNode->pright;
    pNode->pright=tmpNode->pLeft;
    tmpNode->pLeft=pNode;

    //更新平衡度
    pNode->nHeight=Max(Height(pNode->pLeft),Height(pNode->pright))+1;
    tmpNode->nHeight=Max(Height(tmpNode->pLeft),Height(tmpNode->pright))+1;

    return tmpNode;
}

/*
 *  双左旋
 *      原理：先右旋，变成简单的左旋
 * */
static struct AVLTree* DoubleRotateWhtiLeft(struct AVLTree* pNode){
    pNode->pLeft=SingleRotateWithRight(pNode->pLeft);
    return SingleRotateWithLeft(pNode);
}

/*
 *  双右旋
 *      原理：先左旋，变成简单的右旋
 * */
static struct AVLTree* DoubleRotateWhtiRight(struct AVLTree* pNode){
    pNode->pright=SingleRotateWithLeft(pNode->pright);
    return SingleRotateWithRight(pNode);
}

