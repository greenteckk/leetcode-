题目描述：给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

解决：
1.定义一个虚拟节点在头节点前
2.再定义两个指针first和second
3.先使first正向走n次，使first和second距离为n
4.然后first和second一起正向走，直到first到表尾
5.删除倒数第n个节点
6.返回dummy->next（因为dummy此时还在头节点前,返回它的后续节点）

细节：虚拟节点处理问题时不需要判空的

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        auto first = dummy, second = dummy;
        while(n--) first = first->next;
        while(first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
