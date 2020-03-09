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

class LinkedList {
 public:
  static ListNode* reverseList(ListNode *head) {
    ListNode *c = head, *p = NULL, *n = NULL;

    while (c) {
      n = c->next;
      c->next = p;
      p = c;
      c = n;
    }

    return p;
  }

  static ListNode* reverseList2(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *newHead = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
  }

  static void printList(ListNode* head) {
    ListNode* node;
    for (node=head;node;node=node->next) {
      cout << node->value << endl;
    }
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  cout << "Original List: " << endl;
  LinkedList::printList(head);
  head = LinkedList::reverseList2(head);
  cout << "Reversed List: " << endl; 
  LinkedList::printList(head);
  cout << "Reversed List: " << endl; 
  head = LinkedList::reverseList(head);
  LinkedList::printList(head);

  getchar();
}