#include <iostream>

#include "catch.hpp"

#include "../src/arraysandstrings.cpp"

TEST_CASE( "Function `only_unique_chars` returns true if a string has only unique characters", "[arraysandstrings][chapterone]" ) {
  SECTION( "All unique chars present returns true" ) {
    std::string str { "abcdefghijkl" };
    REQUIRE( only_unique_chars(&str) );
  }
  SECTION( "Duplicate chars present returns false" ) {
    std::string str { "abcdefabcxef" };
    REQUIRE_FALSE( only_unique_chars(&str) );
  }
  SECTION( "Duplicate mixed-case chars present returns false" ) {
    std::string str { "ABCabc" };
    REQUIRE_FALSE( only_unique_chars(&str) );
  }
  SECTION( "Empty string throws exception" ) {
    std::string str;
    REQUIRE_THROWS_WITH( only_unique_chars(&str), "Empty string is both unique and not unique." );
  }
}

TEST_CASE( "Function `reverse` reverses the characters of a C-style string in place", "[arraysandstrings][chapterone]" ) {
  SECTION( "Normal string reverses as expected" ) {
    char forwards[] = "Hello World";
    char reversed[] = "dlroW olleH";
    reverse(forwards);
    REQUIRE( strcmp(forwards,reversed) == 0 );
  }
  SECTION( "Empty string throws exception" ) {
    char forwards[0];
    REQUIRE_THROWS_WITH( reverse(forwards), "Empty string cannot be reversed." );
  }
}

TEST_CASE( "Function `bad_compression` performs a bad compression", "[arraysandstrings][chapterone]" ) {
  SECTION( "Normal string compresses as expected" ) {
    std::string uncompressed = "aabbbcc";
    std::string act_compressed = bad_compression(uncompressed);
    std::string exp_compressed = "a2b3c2";
    REQUIRE( act_compressed == exp_compressed );
  }
  SECTION( "Compression is never longer" ) {
    std::string test_cases[] {
      "asdachbhjbhkhjjsdhbchee",
      "hhagdndhddkdhehet",
      "iiihsnwnwwwjfbche",
      "qwertyqwertyqqwweerrttyy"
    };
    for (const std::string& str : test_cases) {
      REQUIRE( bad_compression(str).length() <= str.length() );
    }
  }
  SECTION( "No invalid characters are present, most importantly numbers" ) {
    std::string str = "aa4bbb9cc";
    REQUIRE_THROWS_WITH( bad_compression(str), "Invalid character in string." );
  }
}

void test_rotate_img() {
  std::cout << "-----1.6 rotate_img-----" << std::endl;
  int image[6][6] = {
    {1,2,3,4,5,6},
    {2,3,4,5,6,7},
    {3,4,5,6,7,8},
    {4,5,6,7,8,9},
    {5,6,7,8,9,0},
    {6,7,8,9,0,1}
  };
  for (int row = 0; row < 6; ++row) {
    for (int col = 0; col < 6; ++col)
      std::cout << image[row][col] << " ";
    std::cout << '\n';
  }
  rotate_img(image, 6);
  for (int row = 0; row < 6; ++row) {
    for (int col = 0; col < 6; ++col)
      std::cout << image[row][col] << " ";
    std::cout << '\n';
  }
}

void test_zero_intercepts() {
  std::cout << "-----1.7 zero_intercepts-----" << std::endl;
  int matrix[6][6] = {
    {1,2,3,4,5,6},
    {2,3,4,5,6,7},
    {3,4,0,6,7,8},
    {4,5,6,7,8,9},
    {5,6,7,8,9,0},
    {6,7,8,9,0,1}
  };
  for (int row = 0; row < 6; ++row) {
    for (int col = 0; col < 6; ++col)
      std::cout << matrix[row][col] << " ";
    std::cout << '\n';
  }
  zero_intercepts(matrix);
  for (int row = 0; row < 6; ++row) {
    for (int col = 0; col < 6; ++col)
      std::cout << matrix[row][col] << " ";
    std::cout << '\n';
  }
}

void run_arraysandstrings_tests() {
  test_rotate_img();
  test_zero_intercepts();
}
