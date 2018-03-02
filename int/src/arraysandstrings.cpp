#include <cstring>
#include <string>

//  1.2
//  Implement a function void reverse(char* str) in C or C++ which
//  reverses a null-terminated string.
void reverse(char *str) {
  size_t str_length = strlen(str);
  for (int index = 0; index < str_length/2; index++) {
    std::swap(str[index], str[str_length-index-1]);
  }
}

//  1.5
//  Implement a method to perform basic string compression using the
//  counts of repeated characters. (aaabbccccd = a3b2c4d) Assume string
//  has only upper and lower case letters (a-z).
std::string bad_compression(std::string str) {
  std::string result = "";
  char last_char = '\0';
  int last_char_count = 0;
  // For each char in string, count if its the same as the last, otherwise
  // append the count of the most recent string of common chars.
  for (char& c : str) {
    if (last_char == c) {
      last_char_count++;
    } else {
      result += last_char;
      if (last_char_count > 1)
        result += std::to_string(last_char_count);
      last_char = c;
      last_char_count = 1;
    }
  }
  // Must be done again because null pointer is not present in loop as
  // a char of a std::string, so we manually add the last char+count.
  result += last_char;
  if (last_char_count > 1)
    result += std::to_string(last_char_count);
  return result;
}

//  1.6
//  Given an image represented by an NxN matrix, where each pixel of the
//  image is 4 bytes, write a method to rotate the image by 90 degrees.
template<class Pixel>
void rotate_img(Pixel *img, int n) {
  // May be more appropriately named rotate_matrix in our reusable imple
  if (n > 1) {
    const int rings_to_spin = n/2;
    // We will effectively 'spin' each ring 90degrees clockwise
    // Second loop is index of which pixel in a rings side we're on
    // Exmaple when ring = 0 and index = 1:
    //  . X . .                   . W . .
    //  . . . Y    rotates to     . . . X
    //  W . . .                   Z . . .
    //  . . Z .                   . . Y .
    for (int ring = 0; ring < rings_to_spin; ring++) {
      for (int index = 0; index < n-(ring*2)-1; index++) {
        auto swap_temp = img[ring][ring+index];
        img[ring][ring+index] = img[n-1-ring-index][ring];
        img[n-1-ring-index][ring] = img[n-1-ring][n-1-ring-index];
        img[n-1-ring][n-1-ring-index] = img[ring+index][n-1-ring];
        img[ring+index][n-1-ring] = swap_temp;
      }
    }
  }
}

//  1.7
//  Write an algorithm such that if an element in an MxN matrix is
//  0, its entire row and column are set to 0
template <size_t rows, size_t cols>
void zero_intercepts(int (&matrix)[rows][cols]) {
  // Using this kind of template to avoid needing row/cols passed in
  // means the matrix must be stack living (known compile time)
  bool* row_flags { new bool[rows] };
  bool* col_flags { new bool[cols] };
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (matrix[row][col] == 0) {
        row_flags[row] = true;
        col_flags[col] = true;
      }
    }
  }
  // 0 intercepting rows to the 0 point
  for (int row = 0; row < rows; ++row) {
    if (row_flags[row]) {
      for (int col = 0; col < cols; ++col) {
        matrix[row][col] = 0;
      }
    }
  }
  // 0 intercepting cols to the 0 point
  for (int col = 0; col < cols; ++col) {
    if (col_flags[col]) {
      for (int row = 0; row < rows; ++row) {
        matrix[row][col] = 0;
      }
    }
  }
}
