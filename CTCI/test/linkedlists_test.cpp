#include "../src/linkedlists.cpp"

void test_delete_dup_nodes() {
  std::cout << "-----2.1 delete_dup_nodes-----" << std::endl;
  SinglelyLinkedList list;
  int x[] { 1,2,5,4,5,6,6,1 };
  for(auto& i : x ) {
    list.create_node(i);
  }
  list.print();
  delete_dup_nodes(&list);
  list.print();
}

void test_from_end() {
  std::cout << "-----2.2 from_end-----" << std::endl;
  SinglelyLinkedList list;
  int x[] { 1,2,5,4,5,9,6,1 };
  for(auto& i : x ) {
    list.create_node(i);
  }
  list.print();
  std::cout << "2'nd from end is: " << from_end(&list, 2)->data << std::endl;
}

void test_delete_node() {
  std::cout << "-----2.3 delete_node-----" << std::endl;
  SinglelyLinkedList list;
  int x[] { 1,2,6,4,5,6,6,1 };
  for(auto& i : x ) {
    list.create_node(i);
  }
  list.print();
  delete_node(list.get_head()->next->next); // 6
  list.print();
}

void test_partition_around() {
  std::cout << "-----2.4 partition_around-----" << std::endl;
  SinglelyLinkedList* list = new SinglelyLinkedList;
  int x[] { 1,2,6,4,5,6,6,1,4,6,8,4,2,3,5,8,9,2 };
  for(auto& i : x ) {
    list->create_node(i);
  }
  list->print();
  partition_around(&list, 5);
  list->print();
}

void test_sum_reversed_digits() {
  std::cout << "-----2.5 sum_reversed_digits-----" << std::endl;
  SinglelyLinkedList list1;
  int x[] { 7,1,6 };
  for(auto& i : x ) {
    list1.create_node(i);
  }
  list1.print();
  SinglelyLinkedList list2;
  int y[] { 5,9,2 };
  for(auto& i : y ) {
    list2.create_node(i);
  }
  list2.print();
  SinglelyLinkedList result = sum_reversed_digits(&list1, &list2);
  result.print();
}

void run_linkedlists_tests() {
  test_delete_dup_nodes();
  test_from_end();
  test_delete_node();
  test_partition_around();
  test_sum_reversed_digits();
}
