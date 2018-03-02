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

void run_linkedlists_tests() {
  test_delete_dup_nodes();
  test_from_end();
  test_delete_node();
}
