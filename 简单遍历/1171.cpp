/*
1171. 从链表中删去总和值为零的连续节点

给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
删除完毕后，请你返回最终结果链表的头节点。
你可以返回任何满足题目要求的答案。
（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

示例 1：

输入：head = [1,2,-3,3,1]
输出：[3,1]
提示：答案 [1,2,1] 也是正确的。

示例 2：

输入：head = [1,2,3,-3,4]
输出：[1,2,4]

示例 3：

输入：head = [1,2,3,-3,-2]
输出：[1]

 

提示：

    给你的链表中可能有 1 到 1000 个节点。
    对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.

*/
//g++ -g 1171.cpp -o test  -std=c++11 2> error.txt
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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


class Solution1 {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_set<int>  hashTable;
        unordered_set<int>  hashTemp;
        ListNode*   currentList = head;
        ListNode*   lastList = new ListNode(0);
        ListNode*   newHeadList = lastList;
        ListNode*   temp;
        int findInHash;

        lastList->val = 0;
        lastList->next = head;
        while(currentList!=NULL){
            findInHash = -currentList->val;
            if(hashTable.find(findInHash)!=end(hashTable)){
                lastList->next = currentList->next;
                delete currentList;
                currentList = lastList->next;
                //continue;
            }else{
                for(auto& i:hashTable){
                //for(unordered_set<int>::iterator i=hashTable.begin();i!=hashTable.end();i++){
                //首先，unordered_set不能随便改key,因为会影响内部元素的位置
                //也可以把所有值一个一个挪出来加上val放到另一个set，但是太麻烦了
                    //i += currentList->val;
                }
                hashTable.insert(currentList->val);
                lastList = currentList;
                currentList = currentList->next;
            }
        }
        hashTable.~unordered_set<int>();
        temp = newHeadList;
        newHeadList = newHeadList->next;
        delete temp;
        return newHeadList;
    }
};

class Solution2 {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> saveAllSum;
        ListNode*   currentList = head;
        ListNode*   lastList = new ListNode(0);
        ListNode*   newHeadList = lastList;
        ListNode*   temp;
        bool        ifFind = false;

        lastList->next = head;
        while(currentList!=NULL){
            ifFind = false;
            if(saveAllSum.size()!=0){
                for(auto& i:saveAllSum){
                    if(i==-currentList->val){
                        lastList->next = currentList->next;
                        delete currentList;
                        currentList = lastList->next;
                        ifFind = true;
                        break;                    
                    }
                }
            }
            if(ifFind == false){
                if(saveAllSum.size()!=0){
                    for(auto& i:saveAllSum){
                        i+=currentList->val;
                    }
                }
                saveAllSum.push_back(currentList->val);
                lastList = currentList;
                currentList = currentList->next;
            }
        }
        //saveAllSum.~vector();
        //这个地方会造成141,147行申请的空间重复
        temp = newHeadList;
        newHeadList = newHeadList->next;
        delete temp;
        return newHeadList;
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        if(head == NULL){
            return NULL;
        }

        vector<pair<int,ListNode*>> saveAllSum;
        ListNode*   currentList = head;
        ListNode*   newHeadList = new ListNode(0);
        newHeadList->next=head;
        ListNode*   temp;

        pair<int,ListNode*> tempPair(currentList->val,newHeadList);
        bool        ifFind = false;

        while(currentList!=NULL){
            ifFind = false;
            if(currentList->val==0){
                if(saveAllSum.size()!=0){
                    saveAllSum.back().second->next->next = currentList->next;
                    currentList = currentList->next;
                    continue;
                }else{
                    newHeadList->next=currentList->next;
                    currentList = currentList->next;
                    continue;
                }
            }
            if(saveAllSum.size()!=0){
                for(vector<pair<int,ListNode*>>::iterator i=saveAllSum.begin(); i!=saveAllSum.end(); i++){
                    if((*i).first==-currentList->val){
                        (*i).second->next = currentList->next;
                        //delete currentList;
                        //heap-use-after-free错误，我在本地没问题，所以说传入的链表不能free节点，会被继续使用。。
                        currentList = (*i).second->next;
                        ifFind = true;
                        int tempValue = (*i).first;
                        while(saveAllSum.end()!=i){
                            saveAllSum.pop_back();
                        }
                        for(vector<pair<int,ListNode*>>::iterator j=saveAllSum.begin(); j!=saveAllSum.end(); j++){
                            (*j).first -= tempValue;
                        }
                        break;                    
                    }
                }
            }
            if(ifFind == false){
                //这个值可以存在，把它造成的影响记录下来
                if(saveAllSum.size()!=0){
                    for(auto& i:saveAllSum){
                        i.first+=currentList->val;
                    }
                    tempPair.first = currentList->val;
                    tempPair.second = saveAllSum.back().second->next;
                }else{//没有分支有可能访问越界
                    newHeadList->next = currentList;
                    tempPair.first = currentList->val;
                    tempPair.second = newHeadList;                    
                }
                saveAllSum.push_back(tempPair);
                currentList = currentList->next;
            }
        }
        //saveAllSum.~vector();
        //这个地方会造成141,147行申请的空间重复
        temp = newHeadList;
        newHeadList = newHeadList->next;
        delete temp;
        return newHeadList;
    }
};

//playground
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().removeZeroSumSublists(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

/*
138	ListNode* stringToListNode(string input) {
   0x0000000000401ddb <+0>:	push   %rbp
   0x0000000000401ddc <+1>:	mov    %rsp,%rbp
   0x0000000000401ddf <+4>:	push   %rbx
   0x0000000000401de0 <+5>:	sub    $0x88,%rsp
   0x0000000000401de7 <+12>:	mov    %rdi,-0x88(%rbp)

139	    // Generate list from the input
140	    vector<int> list = stringToIntegerVector(input);
   0x0000000000401dee <+19>:	mov    -0x88(%rbp),%rdx
=> 0x0000000000401df5 <+26>:	lea    -0x40(%rbp),%rax
   0x0000000000401df9 <+30>:	mov    %rdx,%rsi
   0x0000000000401dfc <+33>:	mov    %rax,%rdi
   0x0000000000401dff <+36>:	callq  0x401750 <_ZNSsC1ERKSs@plt>
   0x0000000000401e04 <+41>:	lea    -0x60(%rbp),%rax
   0x0000000000401e08 <+45>:	lea    -0x40(%rbp),%rdx
   0x0000000000401e0c <+49>:	mov    %rdx,%rsi
   0x0000000000401e0f <+52>:	mov    %rax,%rdi
   0x0000000000401e12 <+55>:	callq  0x401c0d <stringToIntegerVector(std::string)>
   0x0000000000401e17 <+60>:	lea    -0x40(%rbp),%rax
   0x0000000000401e1b <+64>:	mov    %rax,%rdi
   0x0000000000401e1e <+67>:	callq  0x4017b0 <_ZNSsD1Ev@plt>

141	
142	    // Now convert that list into linked list
143	    ListNode* dummyRoot = new ListNode(0);
   0x0000000000401e23 <+72>:	mov    $0x10,%edi
   0x0000000000401e28 <+77>:	callq  0x4019b0 <_Znwm@plt>
   0x0000000000401e2d <+82>:	mov    %rax,%rbx
   0x0000000000401e30 <+85>:	mov    $0x0,%esi
   0x0000000000401e35 <+90>:	mov    %rbx,%rdi
   0x0000000000401e38 <+93>:	callq  0x40281e <ListNode::ListNode(int)>
   0x0000000000401e3d <+98>:	mov    %rbx,-0x20(%rbp)

144	    ListNode* ptr = dummyRoot;
   0x0000000000401e41 <+102>:	mov    -0x20(%rbp),%rax
   0x0000000000401e45 <+106>:	mov    %rax,-0x18(%rbp)

145	    for(int item : list) {
   0x0000000000401e49 <+110>:	lea    -0x60(%rbp),%rax
   0x0000000000401e4d <+114>:	mov    %rax,-0x28(%rbp)
   0x0000000000401e51 <+118>:	mov    -0x28(%rbp),%rax
   0x0000000000401e55 <+122>:	mov    %rax,%rdi
   0x0000000000401e58 <+125>:	callq  0x402d92 <std::vector<int, std::allocator<int> >::begin()>
   0x0000000000401e5d <+130>:	mov    %rax,-0x70(%rbp)
   0x0000000000401e61 <+134>:	mov    -0x28(%rbp),%rax
   0x0000000000401e65 <+138>:	mov    %rax,%rdi
   0x0000000000401e68 <+141>:	callq  0x402db8 <std::vector<int, std::allocator<int> >::end()>
   0x0000000000401e6d <+146>:	mov    %rax,-0x80(%rbp)
   0x0000000000401e71 <+150>:	jmp    0x401ebe <stringToListNode(std::string)+227>
   0x0000000000401e73 <+152>:	lea    -0x70(%rbp),%rax
   0x0000000000401e77 <+156>:	mov    %rax,%rdi
   0x0000000000401e7a <+159>:	callq  0x402e3e <__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x0000000000401e7f <+164>:	mov    (%rax),%eax
---Type <return> to continue, or q <return> to quit---
   0x0000000000401e81 <+166>:	mov    %eax,-0x2c(%rbp)
   0x0000000000401eb2 <+215>:	lea    -0x70(%rbp),%rax
   0x0000000000401eb6 <+219>:	mov    %rax,%rdi
   0x0000000000401eb9 <+222>:	callq  0x402e1e <__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >::operator++()>
   0x0000000000401ebe <+227>:	lea    -0x80(%rbp),%rdx
   0x0000000000401ec2 <+231>:	lea    -0x70(%rbp),%rax
   0x0000000000401ec6 <+235>:	mov    %rdx,%rsi
   0x0000000000401ec9 <+238>:	mov    %rax,%rdi
   0x0000000000401ecc <+241>:	callq  0x402de1 <__gnu_cxx::operator!=<int*, std::vector<int, std::allocator<int> > >(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > > const&, __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > > const&)>
   0x0000000000401ed1 <+246>:	test   %al,%al
   0x0000000000401ed3 <+248>:	jne    0x401e73 <stringToListNode(std::string)+152>

146	        ptr->next = new ListNode(item);
   0x0000000000401e84 <+169>:	mov    $0x10,%edi
   0x0000000000401e89 <+174>:	callq  0x4019b0 <_Znwm@plt>
   0x0000000000401e8e <+179>:	mov    %rax,%rbx
   0x0000000000401e91 <+182>:	mov    -0x2c(%rbp),%eax
   0x0000000000401e94 <+185>:	mov    %eax,%esi
   0x0000000000401e96 <+187>:	mov    %rbx,%rdi
   0x0000000000401e99 <+190>:	callq  0x40281e <ListNode::ListNode(int)>
   0x0000000000401e9e <+195>:	mov    -0x18(%rbp),%rax
   0x0000000000401ea2 <+199>:	mov    %rbx,0x8(%rax)

147	        ptr = ptr->next;
   0x0000000000401ea6 <+203>:	mov    -0x18(%rbp),%rax
   0x0000000000401eaa <+207>:	mov    0x8(%rax),%rax
   0x0000000000401eae <+211>:	mov    %rax,-0x18(%rbp)

148	    }
149	    ptr = dummyRoot->next;
   0x0000000000401ed5 <+250>:	mov    -0x20(%rbp),%rax
   0x0000000000401ed9 <+254>:	mov    0x8(%rax),%rax
   0x0000000000401edd <+258>:	mov    %rax,-0x18(%rbp)

150	    delete dummyRoot;
   0x0000000000401ee1 <+262>:	mov    -0x20(%rbp),%rax
   0x0000000000401ee5 <+266>:	mov    %rax,%rdi
   0x0000000000401ee8 <+269>:	callq  0x4016e0 <_ZdlPv@plt>

151	    return ptr;
   0x0000000000401eed <+274>:	mov    -0x18(%rbp),%rbx
   0x0000000000401ef1 <+278>:	lea    -0x60(%rbp),%rax
   0x0000000000401ef5 <+282>:	mov    %rax,%rdi
   0x0000000000401ef8 <+285>:	callq  0x402d28 <std::vector<int, std::allocator<int> >::~vector()>
   0x0000000000401efd <+290>:	mov    %rbx,%rax
   0x0000000000401f00 <+293>:	jmp    0x401f36 <stringToListNode(std::string)+347>
   0x0000000000401f02 <+295>:	mov    %rax,%rbx
   0x0000000000401f05 <+298>:	lea    -0x40(%rbp),%rax
   0x0000000000401f09 <+302>:	mov    %rax,%rdi
   0x0000000000401f0c <+305>:	callq  0x4017b0 <_ZNSsD1Ev@plt>
   0x0000000000401f11 <+310>:	mov    %rbx,%rax
   0x0000000000401f14 <+313>:	mov    %rax,%rdi
   0x0000000000401f17 <+316>:	callq  0x4019c0 <_Unwind_Resume@plt>
   0x0000000000401f1c <+321>:	mov    %rax,%rbx
---Type <return> to continue, or q <return> to quit---
   0x0000000000401f1f <+324>:	lea    -0x60(%rbp),%rax
   0x0000000000401f23 <+328>:	mov    %rax,%rdi
   0x0000000000401f26 <+331>:	callq  0x402d28 <std::vector<int, std::allocator<int> >::~vector()>
   0x0000000000401f2b <+336>:	mov    %rbx,%rax
   0x0000000000401f2e <+339>:	mov    %rax,%rdi
   0x0000000000401f31 <+342>:	callq  0x4019c0 <_Unwind_Resume@plt>

152	}
   0x0000000000401f36 <+347>:	add    $0x88,%rsp
   0x0000000000401f3d <+354>:	pop    %rbx
   0x0000000000401f3e <+355>:	pop    %rbp
   0x0000000000401f3f <+356>:	retq   

End of assembler dump.
/////////////////////////////
=================================================================
==29==ERROR: AddressSanitizer: heap-use-after-free on address 0x602000000078 at pc 0x00000048e704 bp 0x7ffcbb1f72b0 sp 0x7ffcbb1f72a8
READ of size 8 at 0x602000000078 thread T0
    #2 0x7febcbcd52e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
0x602000000078 is located 8 bytes inside of 16-byte region [0x602000000070,0x602000000080)
freed by thread T0 here:
    #0 0x7febcd6fc0d8 in operator delete(void*, unsigned long) (/usr/local/lib64/libasan.so.5+0xeb0d8)
    #2 0x7febcbcd52e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
previously allocated by thread T0 here:
    #0 0x7febcd6face0 in operator new(unsigned long) (/usr/local/lib64/libasan.so.5+0xe9ce0)
    #4 0x7febcbcd52e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa fd fd fa fa fd fd fa fa fd fd fa fa fd[fd]
  0x0c047fff8010: fa fa 00 00 fa fa 00 00 fa fa fd fd fa fa fd fd
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==29==ABORTING
*/