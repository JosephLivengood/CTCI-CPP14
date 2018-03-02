#include <iostream>

#include "../src/arraysandstrings.cpp"

void test_reverse() {
  std::cout << "-----1.2 reverse-----" << std::endl;
  char str[] = "Hello World";
  std::cout << str << std::endl;
  reverse(str);
  std::cout << str << std::endl;
}

void test_bad_compression() {
  std::cout << "-----1.5 bad_compression-----" << std::endl;
  std::string str2 = "aaaabbbsbsdddddgerrr";
  std::cout << str2 << std::endl;
  std::cout << bad_compression(str2) << std::endl;
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
  test_reverse();
  test_bad_compression();
  test_rotate_img();
  test_zero_intercepts();
}
