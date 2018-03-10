#include "catch.hpp"

#include "../src/linkedlists.cpp"

TEST_CASE( "Function `delete_dup_nodes` removed duplicate data nodes and preserves order", "[linkedlists][chaptertwo]" ) {
  SECTION( "Duplicate nodes in middle are removed as expected" ) {
    int init_seed[] { 1,2,4,3,4,6,9 };
    int expe_seed[] { 1,2,4,3,6,9 };
    SinglelyLinkedList init_list { init_seed, 7 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    REQUIRE( init_list.equals(&expe_list) == false );
    delete_dup_nodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "Duplicate nodes at end are removed as expected" ) {
    int init_seed[] { 1,2,4,3,4,6,9,2,2 };
    int expe_seed[] { 1,2,4,3,6,9 };
    SinglelyLinkedList init_list { init_seed, 9 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    REQUIRE( init_list.equals(&expe_list) == false );
    delete_dup_nodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "All of one node returns a single noded list" ) {
    int init_seed[] { 5,5,5 };
    int expe_seed[] { 5 };
    SinglelyLinkedList init_list { init_seed, 3 };
    SinglelyLinkedList expe_list { expe_seed, 1 };
    REQUIRE( init_list.equals(&expe_list) == false );
    delete_dup_nodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "Empty list does not throw exception or modify list" ) {
    SinglelyLinkedList init_list;
    SinglelyLinkedList expe_list;
    REQUIRE( init_list.equals(&expe_list) );
    REQUIRE_NOTHROW( delete_dup_nodes(&init_list) );
    REQUIRE( init_list.equals(&expe_list) );
  }
}


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

void test_find_first_of_circular() {
  std::cout << "-----2.6 find_first_of_circular-----" << std::endl;
  SinglelyLinkedList list;
  int x[] { 1,2,6,4,5,6,6,1,4,6,8,4,2,3,5,8,9,2 };
  for(auto& i : x ) {
    list.create_node(i);
  }
  list.print();
  // corrupt ourselves to be circular
  {
    node* curr = list.get_head();
    for (int i = 0; i < 4; ++i) {
      curr = curr->next;
    }
    node* last = list.get_tail();
    last->next = curr;
  }
  std::cout << "Last node (2) linked to first (5) in the list at position 4." << std::endl;
  node* result = find_first_of_circular(&list);
  std::cout << "First node of circularly corrupted linked list is: " << result->data << std::endl;
  // list->print(); // Dont try to print a circular corrupt list people
}

void test_is_palindrome() {
  std::cout << "-----2.7 is_palindrome-----" << std::endl;
  SinglelyLinkedList list;
  int x[] { 1,2,5,2,6,8 };
  for(auto& i : x ) {
    list.create_node(i);
  }
  list.print();
  std::cout << is_palindrome(&list) << std::endl;
  SinglelyLinkedList list2;
  int x2[] { 1,2,7,2,1 };
  for(auto& i : x2 ) {
    list2.create_node(i);
  }
  list2.print();
  std::cout << is_palindrome(&list2) << std::endl;
  SinglelyLinkedList list3;
  int x3[] { 1,2,7,7,2,1 };
  for(auto& i : x3 ) {
    list3.create_node(i);
  }
  list3.print();
  std::cout << is_palindrome(&list3) << std::endl;
}

void run_linkedlists_tests() {
  test_delete_dup_nodes();
  test_from_end();
  test_delete_node();
  test_partition_around();
  test_sum_reversed_digits();
  test_find_first_of_circular();
  test_is_palindrome();
}
