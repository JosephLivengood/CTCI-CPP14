#include "catch.hpp"

#include "../src/stacks-and-queues.cpp"

TEST_CASE( "Class `Stack` is a functioning stack",
          "[stacksandqueues][chapterthree]" ) {
  
  SECTION( "Integer seeded stack works as expected" ) {
    int seed[] { 5,4,3 };
    Stack<int> stack { seed, 3 };
    REQUIRE_FALSE( stack.isEmpty() );
    
    SECTION( "Top gives next element without removing" ) {
      REQUIRE( stack.top() == 3 );
      REQUIRE( stack.top() == 3 );
      
      SECTION( "Pop will remove the top element and is exception safe" ) {
        REQUIRE_NOTHROW( stack.pop() );
        REQUIRE( stack.top() == 4 );
        REQUIRE_NOTHROW( stack.pop() );
        REQUIRE( stack.top() == 5 );
        REQUIRE_NOTHROW( stack.pop() );
        REQUIRE( stack.isEmpty() );
        REQUIRE_NOTHROW( stack.pop() );
        
        SECTION( "Checking the top of an empty stack throws exeception" ) {
          REQUIRE( stack.isEmpty() );
          REQUIRE_THROWS_WITH( stack.top(), "Stack is empty" );
          
          SECTION( "Pushing adds to the stack in correctly and in order" ) {
            REQUIRE_NOTHROW( stack.push(7) );
            REQUIRE_NOTHROW( stack.push(1) );
            REQUIRE( stack.top() == 1 );
            REQUIRE_NOTHROW( stack.pop() );
            REQUIRE( stack.top() == 7 );
          }
        }
      }
    }
  }
  SECTION( "Char unseeded stack works as expected" ) {
    Stack<char> stack;
    REQUIRE( stack.isEmpty() );
    REQUIRE_NOTHROW( stack.push('a') );
    REQUIRE_NOTHROW( stack.push('b') );
    REQUIRE_NOTHROW( stack.push('c') );
    REQUIRE_FALSE( stack.isEmpty() );
    
    SECTION( "Top gives next element without removing" ) {
      REQUIRE( stack.top() == 'c' );
      REQUIRE( stack.top() == 'c' );
      
      SECTION( "Pop will remove the top element and is exception safe" ) {
        REQUIRE_NOTHROW( stack.pop() );
        REQUIRE( stack.top() == 'b' );
        REQUIRE_NOTHROW( stack.pop() );
        REQUIRE( stack.top() == 'a' );
        REQUIRE_NOTHROW( stack.pop() );
        REQUIRE( stack.isEmpty() );
        REQUIRE_NOTHROW( stack.pop() );
        
        SECTION( "Checking the top of an empty stack throws exeception" ) {
          REQUIRE( stack.isEmpty() );
          REQUIRE_THROWS_WITH( stack.top(), "Stack is empty" );
          
          SECTION( "Pushing adds to the stack in correctly and in order" ) {
            REQUIRE_NOTHROW( stack.push('z') );
            REQUIRE_NOTHROW( stack.push('y') );
            REQUIRE( stack.top() == 'y' );
            REQUIRE_NOTHROW( stack.pop() );
            REQUIRE( stack.top() == 'z' );
          }
        }
      }
    }
  }
}
