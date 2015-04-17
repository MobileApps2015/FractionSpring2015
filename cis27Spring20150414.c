/**
 * Program Name: cis27Spring20150414.c
 * Discussion:   BST Node Removal
 * Written By:   Your Name
 * Date:         2015/04/14
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

//const int MAX_SIZE = 5;

struct IntNode {
  int data;
  struct IntNode* next;
};

typedef struct IntNode INode;
typedef struct IntNode* INodeAddr;
typedef struct IntNode* IList;
typedef struct IntNode* INodePtr;

struct FractionNode {
  int num;
  int denom;
  struct FractionNode* next;
};

typedef struct FractionNode FracN;
typedef FracN* FrAddr;
typedef FracN* FrPtr;
typedef FracN* FrList;

struct Fraction {
  int num;
  int denom;
};

typedef struct Fraction Frac;
typedef Frac* FracAddr;
typedef Frac* FracPtr;

struct FracStack1 {
  FracPtr stkAry[MAX_SIZE];
  int top;
};

typedef struct FracStack1 FracStk1;
typedef FracStk1* FracStk1Ptr;

struct FracStack2 {
  FracPtr* stkDataPtr;
  int StkSize;
  int top;
};

struct FracNode {
  Frac fr;
  struct FracNode* next;
};

typedef struct FracNode FrNode;
typedef FrNode* FrNodeAddr;
typedef FrNode* FrNodePtr;

struct FracStack3 {
  int stkSize;
  FrNodePtr frNodePtr;
};

typedef struct FracStack3 FrStk3;
typedef FrStk3* FrStk3Ptr; // Quiz #8 -- 2015/03/17
/*
struct BSTIntNode {
  int data;
  struct BSTIntNode* left;
  struct BSTIntNode* right;
};
*/

// Prototypes
FrNodePtr createFrNode(void);
FrStk3Ptr createFrNodeStk(void);
void pushFrNode(FrStk3Ptr, FrNodePtr);
void freeFrStk3(FrStk3Ptr);

FracAddr popSecond(FrStk3Ptr);

FracAddr createFrac(void);
int pushFracStk(FracStk1, FracAddr);
FracStk1Ptr createFracStk(void);

FrAddr createFrN(void);

void insertIntSecond(IList* headAddr, INodeAddr nodeAddr);

int swapFirstSecondVersion1(IList* headAddr);

INodeAddr** extractSwapInfo(IList*, int, int);

void display2(int iCount);

void printList(IList head);

// Write a function named as printEvenBackward() or
// printEvenBackwardRecursive() that will print
// all EVEN integers starting from the last node back to 
// the first node.

// BST Node
struct BSTIntNode {
  int data;
  struct BSTIntNode* left;
  struct BSTIntNode* right;
};

//void displayPreOrder(TreePtr myTree) {
void displayPreOrder(struct BSTIntNode* myTree) {
  if (myTree) {
    printf("\n\tValue of node : %d", myTree->data);
    displayPreOrder(myTree->left);
    displayPreOrder(myTree->right);
  }
  return;
}

void insertBST(struct BSTIntNode**, int);

void insertRecurBST(struct BSTIntNode**, struct BSTIntNode*);

void removeBST(struct BSTIntNode** myTreeAddr, int value);

int find(int aValue, TreePtr myTree);

int main() {
  struct BSTIntNode* myTree = 0;

  struct BSTIntNode node1;
  struct BSTIntNode node2;
  struct BSTIntNode node3;

  struct BSTIntNode* nodePtr1;
  struct BSTIntNode* nodePtr2;
  struct BSTIntNode* nodePtr3;

  int option; // 1 : yes  2 : no
  int value;

  struct BSTIntNode* myNewTree = 0;

  node1.data = 5;
  node1.left = 0;
  node1.right = 0;

  node2.data = 9;
  node2.left = 0;
  node2.right = 0;

  node3.data = -8;
  node3.left = 0;
  node3.right = 0;

  myTree = &node1;
  myTree->left = &node2;
  myTree->left->left = &node3;

  displayPreOrder(myTree);

  nodePtr1 = (struct BSTIntNode*) malloc(sizeof(struct BSTIntNode));
  nodePtr1->data = 12;
  nodePtr1->left = 0;
  nodePtr1->right = 0;

  nodePtr2 = (struct BSTIntNode*) malloc(sizeof(struct BSTIntNode));
  nodePtr2->data = 24;
  nodePtr2->left = 0;
  nodePtr2->right = 0;

  nodePtr3 = (struct BSTIntNode*) malloc(sizeof(struct BSTIntNode));
  nodePtr3->data = -243;
  nodePtr3->left = 0;
  nodePtr3->right = 0;

  myTree->left->right = nodePtr1;
  myTree->right = nodePtr3;
  myTree->right->right = nodePtr2;

  displayPreOrder(myTree);

  do {
    printf("\nEnter the option to continue (1 : Yes, 2 : No) ");
    scanf("%d", &option);
    switch (option) {
    case 1:
      printf("\n\tEnter the value to be inserted: ");
      scanf("%d", &value);

      insertBST(&myNewTree, value);
      break;
    case 2:
      printf("\n\tQuit\n");
      break;
    default:
      printf("\nt\tWrong Option!\n");
    }
  } while (option != 2);

  displayPreOrder(myNewTree);

  if (find(5, myNewTree)) {
    removeBST(&myNewTree, 5) ;
  }

  return 0;
}

// Function Definitions

int find(int aValue, struct BSTIntNode* myTree) {
  struct BSTIntNode* nodePtr = myTree;
  int returnFlag = 0;

  while (nodePtr) {
    if (nodePtr->data == aValue && !returnFlag) {
      //return 1;
      returnFlag = 1;
    } else if (aValue < nodePtr->data) {
      nodePtr = nodePtr->left;
    } else {
      nodePtr = nodePtr->right;
    }
  }
  return returnFlag;
}

void removeBST(struct BSTIntNode** myTreeAddr, int value) {
  struct BSTIntNode* travPtr;
  struct BSTIntNode* tmpPtr;

  travPtr = *myTreeAddr;
  if ((*myTreeAddr)->data == value) {
    if ((*myTreeAddr)->left == 0 && (*myTreeAddr)->right == 0) {
      *myTreeAddr = 0;
    } else if (((*myTreeAddr)->left == 0) != ((*myTreeAddr)->right == 0)) {
      (*myTreeAddr) = ((*myTreeAddr)->left == 0) ? (*myTreeAddr)->right :
        (*myTreeAddr)->left;
    } else {
      tmpPtr = (*myTreeAddr)->left;

      while (tmpPtr->right != 0) {
        tmpPtr = tmpPtr->right;
      }

      tmpPtr->right = (*myTreeAddr)->right;
      *myTreeAddr = (*myTreeAddr)->left;
    }

    free(travPtr);
  } else if ((*myTreeAddr)->data > value) {
    removeBST(&(*myTreeAddr)->left, value);
  } else {
    removeBST(&(*myTreeAddr)->right, value);
  }

  // assuming the node was found
  if (travPtr->data == value) {

    // removing a leaf
    travPtr = 0; // + freeing the node

    // removing a node with one child node, which may be
    //   - Left child, or
    //   - Right child
    travPtr = travPtr->left; //or travPtr->right + freeing the node
    
    // remmoving node with 2 child nodes
    //   - Making 2 connections
    //   - Then freeing the node
  }
}

void insertRecurBST(struct BSTIntNode** myTreeAddr, 
                    struct BSTIntNode* nodeAddr) {
  if (*myTreeAddr == 0) {
    *myTreeAddr = nodeAddr;
  } else if ((*myTreeAddr)->data > nodeAddr->data) {
    insertRecurBST(&((*myTreeAddr)->left), nodeAddr);
  } else {
    insertRecurBST(&((*myTreeAddr)->right), nodeAddr);
  }
}

void insertBST(struct BSTIntNode** myTreeAddr, int value) {
  struct BSTIntNode* nodePtr;

  nodePtr = (struct BSTIntNode*) malloc(sizeof(struct BSTIntNode));
  nodePtr->data = value;
  nodePtr->left = 0;
  nodePtr->right = 0;

  insertRecurBST(myTreeAddr, nodePtr);
}

void pushFrNode(FrStk3Ptr stkPtr, FrNodePtr nPtr) {
  /*
  if (stkPtr->stkSize == 0) {
    //stkPtr->frNodePtr = nPtr;
    //stkPtr->stkSize++;
  } else {
    nPtr->next = stkPtr->frNodePtr;
    //stkPtr->frNodePtr = nPtr;
    //stkPtr->stkSize++;
  }
  */

  if (stkPtr->stkSize != 0) {
    nPtr->next = stkPtr->frNodePtr;
  }
  stkPtr->frNodePtr = nPtr;
  stkPtr->stkSize++;
}
FrStk3Ptr createFrNodeStk() {
  FrStk3Ptr tmpPtr;

  tmpPtr = (FrStk3Ptr) malloc(sizeof(FrStk3));
  tmpPtr->stkSize = 0;
  tmpPtr->frNodePtr = 0;

  return tmpPtr;
}

FrNodePtr createFrNode() {
  FrNodePtr frNodePtr;

  frNodePtr = (FrNodePtr) malloc(sizeof(FrNode));
  frNodePtr->next = 0;

  scanf("%d", &(frNodePtr->fr.num));
  scanf("%d", &(frNodePtr->fr.denom));

  return frNodePtr;
}

FracStk1Ptr createFracStk() {
  FracStk1Ptr frStkPtr;
  int i;

  frStkPtr = (FracStk1Ptr) malloc(sizeof(FracStk1));
  frStkPtr->top = -1;
  
  for (i = 0; i < MAX_SIZE; i++) {
    *(frStkPtr->stkAry + i) = 0;
  }

  return frStkPtr;
}

int pushFracStk(FracStk1 fracStk1, FracAddr fracAddr) {
  int flag = 0;
  if (++fracStk1.top < MAX_SIZE) {
    fracStk1.stkAry[fracStk1.top] = fracAddr;
    flag = 1;
  } else {
    fracStk1.top--;
  }

  return flag;
}

FracAddr createFrac() {
  FracPtr frPtr;

  frPtr = (FracAddr) malloc(sizeof(Frac));
  printf("\nEnter an int for num: ");
  scanf("%d", &(frPtr->num));

  do {
    printf("\nEnter a non-zero int for denom: ");
    scanf("%d", &frPtr->denom);
  } while (frPtr->denom == 0);

}

FrAddr createFrN() {
  FrPtr frPtr = 0;
  frPtr = (FrAddr) malloc(sizeof(FracN));

  scanf("%d", &(frPtr->num));
  scanf("%d", &(frPtr->denom));

  if (frPtr->denom < 0) {
    frPtr->num = -frPtr->num;
    frPtr->denom = -frPtr->denom;
  }
  frPtr->next = 0;

  if (frPtr->denom == 0) {
    free(frPtr);

    frPtr = 0;
  }

  return frPtr;
}

void display2(int iCount) {
  printf("Calling display2() -- iCount : %d\n", iCount);
  if (iCount > 0) {
    printf("\tGreeting! -- %d\n", iCount);
    display2(iCount - 1);
  }
  printf("Returning display2() -- iCount : %d\n", iCount);
  return;
}

INodeAddr** extractSwapInfo(IList* headAddr, int m, int n) {
  INodeAddr* ptrPtr = 0;
  INodeAddr** ptrPtrPtr = 0;

  INodeAddr* ptrPtrMp;
  INodeAddr* ptrPtrMc;

  INodeAddr* ptrPtrNp;
  INodeAddr* ptrPtrNc;

  INode aNode;
  int i;

  ptrPtr = &aNode.next;

  // TODO
  //(INodeAddr**) malloc(4 * sizeof(INodeAddr*));

  ptrPtrPtr = (INode***) malloc(4 * sizeof(INodeAddr*));

  //i = 0;
  i = 1;
  ptrPtrMp = headAddr;
  ptrPtrMc = &((*headAddr)->next);
  while (i < m) {
    ptrPtrMp = ptrPtrMc;
    ptrPtrMc = &((*ptrPtrMc)->next);
  }

  i = 1;
  ptrPtrNp = headAddr;
  ptrPtrNc = &((*headAddr)->next);
  while (i < n) {
    ptrPtrNp = ptrPtrNc;
    ptrPtrNc = &((*ptrPtrNc)->next);
  }

  return ptrPtrPtr;
}

int swapFirstSecondVersion1(IList* headAddr) {
  int flag = 0;
  INodePtr tmpAddr1;
  INodePtr tmpAddr2;
  INodePtr tmpAddr3;
  int count = 0;

  tmpAddr1 = *headAddr;
  //while (*headAddr != 0) {
  while (tmpAddr1 != 0 && count != 2) {
    count++;
    tmpAddr1 = tmpAddr1->next;
  }

  if (count == 2) {
    flag = 1;

    //tmpAddr1 = (*headAddr)->next;
    tmpAddr1 = *headAddr;
    //tmpAddr2 = (*headAddr)->next->next;

    //tmpAddr3 = *headAddr;
    *headAddr = (*headAddr)->next;
    //(*headAddr)->next = tmpAddr3;
    (*headAddr)->next = tmpAddr1;

    //tmpAddr1 = tmpAddr2;
    //tmpAddr1->next = tmpAddr2;
    tmpAddr1->next = tmpAddr1->next->next;
  }

  return flag;
}

void insertIntSecond(IList* headAddr, INodeAddr nodeAddr) {
  if (*headAddr != 0) {
    nodeAddr->next = (*headAddr)->next;
    (*headAddr)->next = nodeAddr;
  } else {
    *headAddr = nodeAddr;
  }
}

// Function Definitions


