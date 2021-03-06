#include <iostream>
#include <unordered_set>
#include <stack>

struct node {
  int data;
  node *next;
};

class SinglelyLinkedList {
private:
  node *head_, *tail_;
public:
  SinglelyLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
  }
  SinglelyLinkedList(int seed[], size_t len) {
    head_ = nullptr;
    tail_ = nullptr;
    for(size_t i = 0; i < len; ++i) {
      create_node(seed[i]);
    }
  }
  node *get_head() {
    return head_;
  }
  node *get_tail() {
    return tail_;
  }
  void set_tail(node *node) {
    tail_ = node;
  }
  void create_node(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    if(head_ == NULL) {
      head_ = temp;
      tail_ = temp;
      temp = NULL;
    } else {
      tail_->next = temp;
      tail_ = temp;
    }
  }
  void print() {
    node *node = head_;
    while(node != nullptr) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << "end" << std::endl;
  }
  bool equals(SinglelyLinkedList *other) {
    node *curr = get_head();
    node *curr_other = other->get_head();
    while (curr != NULL && curr_other != NULL) {
      if (curr->data != curr_other->data) {
        return false;
      }
      curr = curr->next;
      curr_other = curr_other->next;
    }
    if (curr != NULL || curr_other != NULL)
      return false;
    return true;
  }
};

//  2.1
//  Write code to remove duplicates from an unsorted linked list.
void DeleteDupNodes(SinglelyLinkedList *list) {
  // Constant time lookup if value exists with unordered_set (hash lookup)
  std::unordered_set<int> existing_values;
  // 2 pointers nessesary for iteration to be able to delete last two
  node *curr = list->get_head();
  node *prev = NULL;
  while (curr != NULL) {
    // Using count instead of find because I don't want to check or
    // even need to check values looping the iterator returned
    if (existing_values.count(curr->data) > 0) {
      prev->next = curr->next;
      delete curr;
    } else {
      existing_values.insert(curr->data);
      prev = curr;
    }
    curr = prev->next;
  }
}

//  2.2
//  Write code to find kth last node of a singly linked list
node *FromEnd(SinglelyLinkedList *list, int k) {
  node *curr = list->get_head();
  node *offset = NULL;
  int elem_num = 0;
  while (curr != NULL) {
    curr = curr->next;
    elem_num++;
    if (elem_num > k) {
      if (offset == NULL) {
        offset = list->get_head(); // initial set
      } else {
        offset = offset->next;
      }
    }
  }
  if (offset == NULL)
    throw std::runtime_error("Parameter `k` cannot be larger than the length of the linked list.");
  return offset;
}

//  2.3
//  Implement an algorithm to delete a node in the middle of a singly
//  linked list, given only access to that node.
void DeleteNode(node *n) {
  if (n->next == NULL) return;
  node *after = n->next;
  n->data = after->data;
  n->next = after->next;
  delete(after);
}

//  2.4
//  Write code to partition a linked list around a value x, such than
//  all nodes < x come before all nodes >= to x.
void PartitionAround(SinglelyLinkedList **list, int x) {
  // Should be a given that order must be preserved based on data structure
  // Two sets for hold lists as we sort before joining, we have a container
  // so we're going to use it for its purpose and NOT manage nodes our self
  SinglelyLinkedList less_than;
  SinglelyLinkedList greater_than;
  
  node *curr = (*list)->get_head();
  while (curr != NULL) {
    if (curr->data < x) {
      less_than.create_node(curr->data);
    } else if (curr->data >= x) {
      greater_than.create_node(curr->data);
    }
    curr = curr->next;
  }
  
  *list = &less_than;
  (*list)->get_tail()->next = greater_than.get_head();
  (*list)->set_tail(greater_than.get_tail());
}

//  2.5
//  You have two numbers represented by a linked list, where each node
//  contains a single digit. The digits are stored in reverse order, such
//  that the 1's digit is at the head of the list. Write a function that
//  adds the two numbers and returns the sum as a linked list.
//
//  INPUT:  (7->1->6) + (5->9->2). That is, 617+295
//  OUTPUT: (2->1->9)
SinglelyLinkedList SumReversedDigits(SinglelyLinkedList *first,
                                     SinglelyLinkedList *second) {
  SinglelyLinkedList result;
  node *curr_first = first->get_head();
  node *curr_second = second->get_head();
  int carry_over = 0;
  while (curr_first != NULL || curr_second != NULL || carry_over != 0 ) {
    int first = 0;
    int second = 0;
    if (curr_first != NULL) {
      first = curr_first->data;
      curr_first = curr_first->next;
    }
    if (curr_second != NULL) {
      second = curr_second->data;
      curr_second = curr_second->next;
    }
    int sum = first + second + carry_over;
    int digit = sum % 10;
    carry_over = sum / 10;
    result.create_node(digit);
  }
  
  return result;
}

//  2.6
//  Given a circular (corrupted) linked list, implement an algorithm
//  which returns the node at the beginning of the loop.
node *FindFirstOfCircular(SinglelyLinkedList *list) {
  node *slow = list->get_head();
  node *fast = list->get_head();

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      break;
    }
  }
  
  slow = list->get_head();
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  
  return slow;
}

//  2.7
//  Implement a function to check if a linked list is a palindrome.
bool IsPalindrome(SinglelyLinkedList *list) {
  // Slow and fast runners to determine mid point
  node *slow = list->get_head();
  node *fast = list->get_head();
  // Elements up to midpoint (where slow runner is when fast finishes*
  std::stack<int> front_half;
  while (fast != NULL && fast->next != NULL) {
    front_half.push(slow->data);
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast != NULL) {
    // Even num elements means the second half starts on the next element
    slow = slow->next;
  }
  while (slow != NULL) {
    if (slow->data != front_half.top()) {
      return false;
    }
    front_half.pop();
    slow = slow->next;
  }
  return true;
}
