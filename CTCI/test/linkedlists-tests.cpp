#include "catch.hpp"

#include "../src/linkedlists.cpp"

TEST_CASE( "Function `delete_dup_nodes` removed duplicate data nodes and preserves order", "[linkedlists][chaptertwo]" ) {
  SECTION( "Duplicate nodes in middle are removed as expected" ) {
    int init_seed[] { 1,2,4,3,4,6,9 };
    int expe_seed[] { 1,2,4,3,6,9 };
    SinglelyLinkedList init_list { init_seed, 7 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    REQUIRE_FALSE( init_list.equals(&expe_list) );
    DeleteDupNodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "Duplicate nodes at end are removed as expected" ) {
    int init_seed[] { 1,2,4,3,4,6,9,2,2 };
    int expe_seed[] { 1,2,4,3,6,9 };
    SinglelyLinkedList init_list { init_seed, 9 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    REQUIRE_FALSE( init_list.equals(&expe_list) );
    DeleteDupNodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "All of one node returns a single noded list" ) {
    int init_seed[] { 5,5,5 };
    int expe_seed[] { 5 };
    SinglelyLinkedList init_list { init_seed, 3 };
    SinglelyLinkedList expe_list { expe_seed, 1 };
    REQUIRE_FALSE( init_list.equals(&expe_list) );
    DeleteDupNodes(&init_list);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "No duplicate nodes in list does not alter list" ) {
    int seed[] { 1,2,3,4,5,6 };
    SinglelyLinkedList test_list { seed, 6 };
    SinglelyLinkedList cont_list { seed, 6 };
    DeleteDupNodes(&test_list);
    REQUIRE( test_list.equals(&cont_list) );
  }
  SECTION( "Empty list does not throw exception or modify list" ) {
    SinglelyLinkedList init_list;
    SinglelyLinkedList expe_list;
    REQUIRE( init_list.equals(&expe_list) );
    REQUIRE_NOTHROW( DeleteDupNodes(&init_list) );
    REQUIRE( init_list.equals(&expe_list) );
  }
}

TEST_CASE( "Function `from_end` returns the k'th node from the end of a linked list", "[linkedlists][chaptertwo]" ) {
  SECTION( "Returns k'th node as expected" ) {
    int seed[] { 1,3,2,4,5,7,6,9 };
    SinglelyLinkedList list { seed, 8 };
    REQUIRE( FromEnd(&list, 1)->data == 6 );
    REQUIRE( FromEnd(&list, 2)->data == 7 );
    REQUIRE( FromEnd(&list, 3)->data == 5 );
    REQUIRE( FromEnd(&list, 4)->data == 4 );
    REQUIRE( FromEnd(&list, 5)->data == 2 );
  }
  SECTION( "Returns k'th node as expected when k is 0" ) {
    int seed[] { 1,3,2,4,5,7,6,9 };
    SinglelyLinkedList list { seed, 8 };
    REQUIRE( FromEnd(&list, 0)->data == 9 );
  }
  SECTION( "Exception is thrown when k is larger than list" ) {
    int seed[] { 1,3,2,4,5,7,6,9 };
    SinglelyLinkedList list { seed, 8 };
    SinglelyLinkedList empty_list;
    REQUIRE_THROWS_WITH( FromEnd(&list, 11), "Parameter `k` cannot be larger than the length of the linked list." );
    REQUIRE_THROWS_WITH( FromEnd(&empty_list, 1), "Parameter `k` cannot be larger than the length of the linked list." );
  }
}

TEST_CASE( "Function `delete_node` deletes a middle node from whatever list its a part of", "[linkedlists][chaptertwo]" ) {
  SECTION( "Deletes node as expected" ) {
    int init_seed[] { 1,3,2,4,5,7,6,9 };
    int expe_seed[] { 1,3,4,5,7,6,9 };
    SinglelyLinkedList init_list { init_seed, 8 };
    SinglelyLinkedList expe_list { expe_seed, 7 };
    node* third_node = init_list.get_head()->next->next;
    DeleteNode(third_node);
    REQUIRE( init_list.equals(&expe_list) );
  }
  SECTION( "Multiple deletes leaves list as expected" ) {
    int init_seed[] { 1,3,2,4,5,7,6,9 };
    int expe_seed[] { 1,3,5,7,6,9 };
    SinglelyLinkedList init_list { init_seed, 8 };
    SinglelyLinkedList expe_list { expe_seed, 6 };
    node* third_node = init_list.get_head()->next->next;
    DeleteNode(third_node);
    third_node = init_list.get_head()->next->next;
    DeleteNode(third_node);
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
    PartitionAround(&init_list_ptr, 3);
    REQUIRE( expe_list.equals(init_list_ptr) );
  }
}

TEST_CASE( "Function `sum_reversed_digits` adds two lists of reversed digits", "[linkedlists][chaptertwo]" ) {
  SECTION( "Adds even lists of digits as expected" ) {
    int first_seed[] { 7,1,6 };
    int second_seed[] { 5,9,2 };
    int expe_seed[] { 2,1,9 };
    SinglelyLinkedList first_list { first_seed, 3 };
    SinglelyLinkedList second_list { second_seed, 3 };
    SinglelyLinkedList expe_list { expe_seed, 3 };
    SinglelyLinkedList result = SumReversedDigits(&first_list, &second_list);
    REQUIRE( result.equals(&expe_list) );
  }
  SECTION( "Adds uneven lists of digits as expected" ) {
    int first_seed[] { 7,1,6 };
    int second_seed[] { 5 };
    int expe_seed[] { 2,2,6 };
    SinglelyLinkedList first_list { first_seed, 3 };
    SinglelyLinkedList second_list { second_seed, 1 };
    SinglelyLinkedList expe_list { expe_seed, 3 };
    SinglelyLinkedList result = SumReversedDigits(&first_list, &second_list);
    REQUIRE( result.equals(&expe_list) );
  }
  SECTION( "Adds an empty list to a populated list of digits as expected" ) {
    int first_seed[] { 7,1,6 };
    int expe_seed[] { 7,1,6 };
    SinglelyLinkedList first_list { first_seed, 3 };
    SinglelyLinkedList second_list;
    SinglelyLinkedList expe_list { expe_seed, 3 };
    SinglelyLinkedList result = SumReversedDigits(&first_list, &second_list);
    REQUIRE( result.equals(&expe_list) );
  }
}

TEST_CASE( "Function `is_palindrome` returns whether lists data is a palindrome", "[linkedlists][chaptertwo]" ) {
  SECTION( "Returns true when expected to be true" ) {
    int seed1[] { 1,2,3,4,3,2,1 }; // odd
    int seed2[] { 1,2,3,3,2,1 };   // even
    int seed3[] { 1 };             // lone
    SinglelyLinkedList list1 { seed1, 7 };
    SinglelyLinkedList list2 { seed2, 6 };
    SinglelyLinkedList list3 { seed3, 1 };
    REQUIRE( IsPalindrome(&list1) );
    REQUIRE( IsPalindrome(&list2) );
    REQUIRE( IsPalindrome(&list3) );
  }
  SECTION( "Returns false when expected to be false" ) {
    int seed1[] { 1,2,3,4,5,2,1 }; // odd
    int seed2[] { 1,2,3,3,2,2 };   // even
    int seed3[] { 9,8 };           // small
    SinglelyLinkedList list1 { seed1, 7 };
    SinglelyLinkedList list2 { seed2, 6 };
    SinglelyLinkedList list3 { seed3, 2 };
    REQUIRE_FALSE( IsPalindrome(&list1) );
    REQUIRE_FALSE( IsPalindrome(&list2) );
    REQUIRE_FALSE( IsPalindrome(&list3) );
  }
}

TEST_CASE( "Function `find_first_of_circular` returns first node of a circularly corrupted linked list", "[linkedlists][chaptertwo]" ) {
  SECTION( "Returns true when expected to be true" ) {
    int seed[] { 1,2,6,4,5,6,6,1,4,6,8,4,2,3,5,8,9,2 };
    SinglelyLinkedList list { seed, 18 };
    node* expe_result;
    {
      // corrupt our list
      node* curr = list.get_head();
      for (int i = 0; i < 4; ++i) {
        curr = curr->next;
      }
      node* last = list.get_tail();
      last->next = curr;
      expe_result = curr;
    }
    node* result = FindFirstOfCircular(&list);
    REQUIRE( result == expe_result );
  }
}
