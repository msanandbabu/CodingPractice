#include <iostream>

using namespace std;

class ListNode {
 public:
  int value;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = NULL;
  }
};

class PalindromicLinkedList {
 public:
  static ListNode* reverseList(ListNode *head) {
    ListNode *node = head, *c, *p, *n;

    p = node = head;
    while (p->next) {
      p = node;
      c = node->next;
      n = c->next;
      
      //put c before head
      c->next = head;
      head = c;
      //reinstate links
      p->next = n;
    }

    return head;
  }

  static void printList(ListNode* head) {
    ListNode* node;
    for (node=head;node;node=node->next) {
      cout << node->value << endl;
    }
  }

  static bool isPalindrome(ListNode *head) {
    // go to mid using slow fast pointer approach
    ListNode *slow = head, *fast=head;
    bool result = true;

    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow = mid point
    // reverse second half
    ListNode* mid = reverseList(slow);
    cout << "1st half " << endl;
    printList(head);
    cout << "2nd half " << endl;
    printList(mid);

    // compare 1st half and 2nd half
    ListNode *node1 = head, *node2 = mid;
    while (node1 && node2) {
      if (node1->value != node2->value) {
        result = false;
        break;
      }
      node1 = node1->next;
      node2 = node2->next;
    }

    // put the list back to original order
    reverseList(mid);

    cout << "Back to original list " << endl;
    printList(head);

    return result;
  }
};

#if 0
int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(6);
  head->next->next->next->next = new ListNode(4);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
  getchar();
}
#endif