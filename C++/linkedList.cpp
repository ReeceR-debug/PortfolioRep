#include <iostream>
using namespace std;

struct node
{
    int val;
    node* pNext;
};

//protypes
void addNode(int nodeVal, node** ppList);
void printList(node* ppList);
void insertNode(int nodeVal, node** ppList);
int main()
{
    node* pList;
    
    pList = NULL;

    addNode(10, &pList);
    addNode(20, &pList);
    addNode(30, &pList);

    printList(pList);
    
    return 0;
}

void addNode(int nodeVal, node** ppList) {
    node* pNew;
    node* pCurr;

    //allocate and fill node
    pNew = new node;
    pNew->val = nodeVal;
    pNew->pNext = NULL;

    //Is this the first node  to add
    if (*ppList == NULL) {

        *ppList = pNew;
        pNew = NULL;
    }
    else {
        pCurr = *ppList;
        //while its not the last node
        while (pCurr->pNext != NULL) {
            //go to he next node
            pCurr = pCurr->pNext;
        }
        //pCurr is pointing to the last node
        //add the new node to the end
        pCurr->pNext = pNew;
        pNew = NULL;
    }

}

void printList(node* ppList) {

    while (ppList != NULL) {
        cout << ppList->val << ' ';
        ppList = ppList->pNext;
    }


}

void insertNode(int nodeVal, node** ppList) {
    node* pNew;
    node* pCurr;
    node* pPrev;

    //allocate and fill node
    pNew = new node;
    pNew->val = nodeVal;
    pNew->pNext = NULL;

    //check if empty
    if (*ppList = NULL) {
        *ppList = pNew;
        pNew = NULL;
    }
    else {

        pCurr = *ppList;

        //traverse the list
        while (pCurr != NULL && pCurr->val < pNew->val) {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
        if (pPrev == NULL) {
            *ppList = pNew;
        }
        else {
            pPrev->pNext = pNew;
        }

        pNew->pNext = pCurr;
        pCurr = NULL;
        pPrev = NULL;
        pNew = NULL;
    }
}