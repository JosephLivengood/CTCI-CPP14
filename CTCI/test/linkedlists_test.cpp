#include "catch.hpp"

#include "../src/linkedlists.cpp"

TEST_CASE( "Function `delete_dup_nodes` removed duplicate data nodes and preserves order", "[linkedlists][chaptertwo]" ) {
  SECTION( "Duplicate nodes in middle are removed as expected" ) {
    int init_seed[] { 1,2,4,3,4,6,9 };
    int expe_seed[] { 1,2,4,3,6,9 };
    SinglelyLinkedList init_list { init_seed, 7 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    REQUIRE_FALSE( init_list.equals(&expe_list) );
    delete_dup_nodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "Duplicate nodes at end are removed as expected" ) {
    int init_seed[] { 1,2,4,3,4,6,9,2,2 };
    int expe_seed[] { 1,2,4,3,6,9 };
    SinglelyLinkedList init_list { init_seed, 9 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    REQUIRE_FALSE( init_list.equals(&expe_list) );
    delete_dup_nodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "All of one node returns a single noded list" ) {
    int init_seed[] { 5,5,5 };
    int expe_seed[] { 5 };
    SinglelyLinkedList init_list { init_seed, 3 };
    SinglelyLinkedList expe_list { expe_seed, 1 };
    REQUIRE_FALSE( init_list.equals(&expe_list) );
    delete_dup_nodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "No duplicate nodes in list does not alter list" ) {
    int seed[] { 1,2,3,4,5,6 };
    SinglelyLinkedList test_list { seed, 6 };
    SinglelyLinkedList cont_list { seed, 6 };
    delete_dup_nodes(&test_list);
    REQUIRE( test_list.equals(&cont_list) );
  }
  SECTION( "Empty list does not throw exception or modify list" ) {
    SinglelyLinkedList init_list;
    SinglelyLinkedList expe_list;
    REQUIRE( init_list.equals(&expe_list) );
    REQUIRE_NOTHROW( delete_dup_nodes(&init_list) );
    REQUIRE( init_list.equals(&expe_list) );
  }
}

TEST_CASE( "Function `from_end` returns the k'th node from the end of a linked list", "[linkedlists][chaptertwo]" ) {
  SECTION( "Returns k'th node as expected" ) {
    int seed[] { 1,3,2,4,5,7,6,9 };
    SinglelyLinkedList list { seed, 8 };
    REQUIRE( from_end(&list, 1)->data == 6 );
    REQUIRE( from_end(&list, 2)->data == 7 );
    REQUIRE( from_end(&list, 3)->data == 5 );
    REQUIRE( from_end(&list, 4)->data == 4 );
    REQUIRE( from_end(&list, 5)->data == 2 );
  }
  SECTION( "Returns k'th node as expected when k is 0" ) {
    int seed[] { 1,3,2,4,5,7,6,9 };
    SinglelyLinkedList list { seed, 8 };
    REQUIRE( from_end(&list, 0)->data == 9 );
  }
  SECTION( "Exception is thrown when k is larger than list" ) {
    int seed[] { 1,3,2,4,5,7,6,9 };
    SinglelyLinkedList list { seed, 8 };
    SinglelyLinkedList empty_list;
    REQUIRE_THROWS_WITH( from_end(&list, 11), "Parameter `k` cannot be larger than the length of the linked list." );
    REQUIRE_THROWS_WITH( from_end(&empty_list, 1), "Parameter `k` cannot be larger than the length of the linked list." );
  }
}

TEST_CASE( "Function `delete_node` deletes a middle node from whatever list its a part of", "[linkedlists][chaptertwo]" ) {
  SECTION( "Deletes node as expected" ) {
    int init_seed[] { 1,3,2,4,5,7,6,9 };
    int expe_seed[] { 1,3,4,5,7,6,9 };
    SinglelyLinkedList init_list { init_seed, 8 };
    SinglelyLinkedList expe_list { expe_seed, 7 };
    node* third_node = init_list.get_head()->next->next;
    delete_node(third_node);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "Multiple deletes leaves list as expected" ) {
    int init_seed[] { 1,3,2,4,5,7,6,9 };
    int expe_seed[] { 1,3,5,7,6,9 };
    SinglelyLinkedList init_list { init_seed, 8 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    node* third_node = init_list.get_head()->next->next;
    delete_node(third_node);
    third_node = init_list.get_head()->next->next;
    delete_node(third_node);
    REQUIRE( init_list.equals(&expe_list) );
  }
}

TEST_CASE( "Function `partition_around` partitions a list around a number preserving order", "[linkedlists][chaptertwo]" ) {
  SECTION( "Partitions node as expected preserving order" ) {
    int init_seed[] { 5,4,3,2,1 };
    int expe_seed[] { 2,1,5,4,3 };
    SinglelyLinkedList init_list { init_seed, 5 };
    SinglelyLinkedList expe_list { expe_seed, 5 };
    SinglelyLinkedList* init_list_ptr = &init_list;
    partition_around(&init_list_ptr, 3);
    REQUIRE( expe_list.equals(init_list_ptr) );
  }
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
  test_sum_reversed_digits();
  test_find_first_of_circular();
  test_is_palindrome();
}
