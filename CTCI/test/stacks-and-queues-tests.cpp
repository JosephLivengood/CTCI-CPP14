#include "catch.hpp"

#include "../src/stacks-and-queues.cpp"

TEST_CASE( "Class `Stack` is a functioning stack",
          "[stacksandqueues][chapterthree]" ) {
  Stack<int> stack { (int []){ 5,4,3 }, 3 };
  Stack<char> charstack;
  
  SECTION( "Popping a seeded stack functions and is in order" ) {
    REQUIRE( stack.Pop() == 3 );
    REQUIRE( stack.Pop() == 4 );
    REQUIRE( stack.Pop() == 5 );
  
    SECTION( "Popping an empty stack results in exeception" ) {
      REQUIRE_THROWS_WITH( stack.Pop(), "Stack is empty" );
      REQUIRE_THROWS_WITH( charstack.Pop(), "Stack is empty" );
  
      SECTION( "Peeking an empty stack results in exeception" ) {
        REQUIRE_THROWS_WITH( stack.Peek(), "Stack is empty" );
        REQUIRE_THROWS_WITH( charstack.Peek(), "Stack is empty" );
      
        SECTION( "Pushing does not return or throw anything" ) {
          REQUIRE_NOTHROW( stack.Push(9) );
          REQUIRE_NOTHROW( stack.Push(3) );
          REQUIRE_NOTHROW( charstack.Push('a') );
        
          SECTION( "Peeking functions as expected" ) {
            REQUIRE( stack.Peek() == 3 );
            REQUIRE( charstack.Peek() == 'a' );
          
            SECTION( "Popping pushed elements functions as expected" ) {
              REQUIRE( stack.Pop() == 3 );
              REQUIRE( charstack.Pop() == 'a' );
            }
          }
        }
      }
    }
  }
}
