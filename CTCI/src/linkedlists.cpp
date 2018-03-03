#include <iostream>
#include <unordered_set>

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
  node* get_head() {
    return head_;
  }
  node* get_tail() {
    return tail_;
  }
  void set_tail(node* node) {
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
    std::cout << std::endl;
  }
};

//  2.1
//  Write code to remove duplicates from an unsorted linked list.
void delete_dup_nodes(SinglelyLinkedList *list) {
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
node* from_end(SinglelyLinkedList* list, int k) {
  node* curr = list->get_head();
  node* offset = NULL;
  while (curr != NULL) {
    curr = curr->next;
    static int elem_num = 0;
    elem_num++;
    if (elem_num > k) {
      if (offset == NULL) {
        offset = list->get_head(); // initial set
      } else {
        offset = offset->next;
      }
    }
  }
  return offset;
}

//  2.3
//  Implement an algorithm to delete a node in the middle of a singly
//  linked list, given only access to that node.
void delete_node(node* n) {
  if (n->next == NULL) return;
  node* after = n->next;
  n->data = after->data;
  n->next = after->next;
  delete(after);
}

//  2.4
//  Write code to partition a linked list around a value x, such than
//  all nodes < x come before all nodes >= to x.
void partition_around(SinglelyLinkedList** list, int x) {
  // Should be a given that order must be preserved based on data structure
  // Two sets for hold lists as we sort before joining, we have a container
  // so we're going to use it for its purpose and NOT manage nodes our self
  SinglelyLinkedList less_than;
  SinglelyLinkedList greater_than;
  
  node* curr = (*list)->get_head();
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
