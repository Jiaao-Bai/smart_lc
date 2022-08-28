//20.2.18
//对空间的要求应该只是函数内部，不算函数调用的栈..我猜
//20.5.30
//快慢指针，归并排序
//常数级空间复杂度 限制了链表拷贝到数组，链表适合归并排序
//链表的问题在于单向链表很难交换节点，所以快速排序不适合
//Definition for singly-linked list.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        int inputListSize = 0;
        int cutSize = 0;        
        ListNode newHead(0);
        ListNode *pLeftBegin, *pRightBegin, *pBeginOfListForCut;
        ListNode *pEndOfList;
        pair<ListNode *,ListNode *> returnFromMerge;
        //init
        inputListSize = countListSize(head);
        newHead.next = head;

        for(cutSize=1;cutSize<inputListSize;cutSize=cutSize<<1){
            pEndOfList = &newHead;
            pLeftBegin = pEndOfList->next;
            pRightBegin = cutList(pLeftBegin, cutSize);
            pBeginOfListForCut = cutList(pRightBegin, cutSize);
            while(pLeftBegin||pRightBegin){
                returnFromMerge = mergeList(pLeftBegin,pRightBegin);                
                pEndOfList->next = returnFromMerge.first;

                pEndOfList = returnFromMerge.second;
                pLeftBegin = pBeginOfListForCut;
                pRightBegin = cutList(pLeftBegin, cutSize);
                pBeginOfListForCut = cutList(pRightBegin, cutSize);
            }
            pEndOfList->next = NULL;
        }
        return newHead.next;
    }

    int countListSize(ListNode* head){
        
        int nodeSize = 0;

        while(head!=NULL){
            head = head->next;
            nodeSize++;
        }

        return nodeSize;        
    }



    ListNode* cutList(ListNode* head, int size){
        
        ListNode* returnNode = NULL;

        while(size!=1&&head!=NULL){
            head = head->next;
            size--;
        }
        if(head!=NULL){
            returnNode = head->next;    
            head->next = NULL;
        }

        return returnNode;
    }
    pair<ListNode *,ListNode *> mergeList(ListNode* pLeftBegin, ListNode* pRightBegin){
        
        pair<ListNode *,ListNode *> ret;
        ListNode newHead(0);
        ListNode *currentNode = &newHead;

        while(pLeftBegin!=NULL&&pRightBegin!=NULL){
            if(pLeftBegin->val<pRightBegin->val){
                currentNode->next = pLeftBegin;
                currentNode = currentNode->next;
                pLeftBegin = pLeftBegin->next;
            }else{
                currentNode->next = pRightBegin;
                currentNode = currentNode->next;
                pRightBegin = pRightBegin->next;
            }
        }
        if(pLeftBegin==NULL){
            while(pRightBegin!=NULL){
                currentNode->next = pRightBegin;
                currentNode = currentNode->next;
                pRightBegin = pRightBegin->next;
            }
        }else{
            while(pLeftBegin!=NULL){
                currentNode->next = pLeftBegin;
                currentNode = currentNode->next;
                pLeftBegin = pLeftBegin->next;
            }
        }
        ret.first = newHead.next;
        ret.second = currentNode;

        return ret;
    }
};


int main(){
    ListNode tempHead(0);
    ListNode *lastNode = &tempHead;
    ListNode *sortResult;
    int input;
    while(cin>>input){
        ListNode *newNode = new ListNode(input);
        lastNode->next = newNode;
        lastNode = newNode;
    }
    lastNode->next = NULL;
    sortResult = Solution().sortList(tempHead.next);
    while(sortResult!=NULL){
        cout<<sortResult->val<<endl;
        sortResult = sortResult->next;
    }
    return 0;
}