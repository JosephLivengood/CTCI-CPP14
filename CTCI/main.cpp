#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "test/arraysandstrings_test.cpp"
#include "test/linkedlists_test.cpp"

TEST_CASE( "1: All test cases reside in `/test` .cpp files", "[multi-file:1]" ) {
  
}

/*
int main(int argc, const char * argv[]) {
  run_arraysandstrings_tests();
  run_linkedlists_tests();
  return 0;
}
*/
