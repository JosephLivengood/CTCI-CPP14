#include "catch.hpp"

#include "../src/arrays-and-strings.cpp"

TEST_CASE( "Function `only_unique_chars` returns true if a string has only unique characters",
           "[arraysandstrings][chapterone]" ) {
  SECTION( "All unique chars present returns true" ) {
    std::string str { "abcdefghijkl" };
    REQUIRE( OnlyUniqueChars(&str) );
  }
  SECTION( "Duplicate chars present returns false" ) {
    std::string str { "abcdefabcxef" };
    REQUIRE_FALSE( OnlyUniqueChars(&str) );
  }
  SECTION( "Duplicate mixed-case chars present returns false" ) {
    std::string str { "ABCabc" };
    REQUIRE_FALSE( OnlyUniqueChars(&str) );
  }
  SECTION( "Empty string throws exception" ) {
    std::string str;
    REQUIRE_THROWS_WITH( OnlyUniqueChars(&str),
                         "Empty string is both unique and not unique." );
  }
}

TEST_CASE( "Function `reverse` reverses the characters of a C-style string in place",
           "[arraysandstrings][chapterone]" ) {
  SECTION( "Normal string reverses as expected" ) {
    char forwards[] = "Hello World";
    char reversed[] = "dlroW olleH";
    Reverse(forwards);
    REQUIRE( strcmp(forwards,reversed) == 0 );
  }
  SECTION( "Empty string throws exception" ) {
    char forwards[0];
    REQUIRE_THROWS_WITH( Reverse(forwards),
                         "Empty string cannot be reversed." );
  }
}

TEST_CASE( "Function `bad_compression` performs a bad compression",
           "[arraysandstrings][chapterone]" ) {
  SECTION( "Normal string compresses as expected" ) {
    std::string uncompressed = "aabbbcc";
    std::string act_compressed = BadCompression(uncompressed);
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
    for (const std::string &str : test_cases) {
      REQUIRE( BadCompression(str).length() <= str.length() );
    }
  }
  SECTION( "No invalid characters are present, most importantly numbers" ) {
    std::string str = "aa4bbb9cc";
    REQUIRE_THROWS_WITH( BadCompression(str), "Invalid character in string." );
  }
}

TEST_CASE( "Function `rotate_img` rotates a matrix 90degrees",
           "[arraysandstrings][chapterone]" ) {
  SECTION( "Small odd matrix is rotated as expected" ) {
    int original_image[3][3] = {
      {1,1,2},
      {4,5,2},
      {4,3,3}
    };
    int rotated_image[3][3] = {
      {4,4,1},
      {3,5,1},
      {3,2,2}
    };
    RotateImg(original_image, 3);
    bool are_equal = true;
    for (size_t row = 0; row < 3; ++row) {
      for (size_t col = 0; col < 3; ++col) {
        if (original_image[row][col] != rotated_image[row][col]) {
          are_equal = false;
        }
      }
    }
    REQUIRE( are_equal );
  }
  SECTION( "Medium even matrix is rotated as expected" ) {
    int original_image[6][6] = {
      {1,2,3,4,5,6},
      {2,3,4,5,6,7},
      {3,4,5,6,7,8},
      {4,5,6,7,8,9},
      {5,6,7,8,9,0},
      {6,7,8,9,0,1}
    };
    int rotated_image[6][6] = {
      {6,5,4,3,2,1},
      {7,6,5,4,3,2},
      {8,7,6,5,4,3},
      {9,8,7,6,5,4},
      {0,9,8,7,6,5},
      {1,0,9,8,7,6}
    };
    RotateImg(original_image, 6);
    bool are_equal = true;
    for (size_t row = 0; row < 6; ++row) {
      for (size_t col = 0; col < 6; ++col) {
        if (original_image[row][col] != rotated_image[row][col]) {
          are_equal = false;
        }
      }
    }
    REQUIRE( are_equal );
  }
  SECTION( "Four rotations preserves matrix " ) {
    int original_image[3][3] = {
      {1,1,2},
      {4,5,2},
      {4,3,3}
    };
    int original_image_copy[3][3] = {
      {1,1,2},
      {4,5,2},
      {4,3,3}
    };
    RotateImg(original_image, 3);
    RotateImg(original_image, 3);
    RotateImg(original_image, 3);
    RotateImg(original_image, 3);
    bool are_equal = true;
    for (size_t row = 0; row < 3; ++row) {
      for (size_t col = 0; col < 3; ++col) {
        if (original_image[row][col] != original_image_copy[row][col]) {
          are_equal = false;
        }
      }
    }
    REQUIRE( are_equal );
  }
}

TEST_CASE( "Function `zero_intercepts` zeros rows and cols which contain a zero",
           "[arraysandstrings][chapterone]" ) {
  SECTION( "Intercepts are zeroed as expected" ) {
    int matrix[6][6] = {
      {1,2,3,4,5,6},
      {2,3,4,5,6,7},
      {3,4,0,6,7,8},
      {4,5,6,7,8,9},
      {5,6,7,8,9,0},
      {6,7,8,9,0,1}
    };
    int zeroed[6][6] = {
      {1,2,0,4,0,0},
      {2,3,0,5,0,0},
      {0,0,0,0,0,0},
      {4,5,0,7,0,0},
      {0,0,0,0,0,0},
      {0,0,0,0,0,0}
    };
    ZeroIntercepts(matrix);
    bool are_equal = true;
    for (size_t row = 0; row < 6; ++row) {
      for (size_t col = 0; col < 6; ++col) {
        if (matrix[row][col] != zeroed[row][col]) {
          are_equal = false;
        }
      }
    }
    REQUIRE( are_equal );
  }
}
