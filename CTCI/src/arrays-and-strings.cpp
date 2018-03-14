#include <cstring>
#include <string>

//  1.1
//  Implement an algorithm to determine if a string has all unique
//  characters. Ignore case.
bool OnlyUniqueChars(std::string *str) {
  if (str->empty())
    throw std::runtime_error("Empty string is both unique and not unique.");
  // int is only 16 bits on LP32, need atleast 26 flags
  long found_flags = 0;
  for (char &c : *str) {
    if ((found_flags >> ((c-'A') % 32) & 1) == 1)
      return false;
    found_flags = found_flags ^ (1 << ((c-'A') % 32));
  }
  return true;
}

//  1.2
//  Implement a function void reverse(char *str) in C or C++ which
//  reverses a null-terminated string.
void Reverse(char *str) {
  size_t str_length = strlen(str);
  if (str_length == 0)
    throw std::runtime_error("Empty string cannot be reversed.");
  for (int index = 0; index < str_length/2; index++) {
    std::swap(str[index], str[str_length-index-1]);
  }
}

//  1.5
//  Implement a method to perform basic string compression using the
//  counts of repeated characters. (aaabbccccd = a3b2c4d) Assume string
//  has only upper and lower case letters (a-z).
std::string BadCompression(std::string str) {
  std::string result;
  char last_char = '\0';
  int last_char_count = 0;
  // For each char in string, count if its the same as the last, otherwise
  // append the count of the most recent string of common chars.
  for (char &c : str) {
    // validate char, function parameters are strictly letters
    if (c < 65 || c > 122)
      throw std::runtime_error("Invalid character in string.");
    if (last_char == c) {
      last_char_count++;
    } else {
      if (last_char != '\0')
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
void RotateImg(Pixel *img, int n) {
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
void ZeroIntercepts(int (&matrix)[rows][cols]) {
  // Using this kind of template to avoid needing row/cols passed in
  // means the matrix must be stack living (known compile time)
  bool *row_flags { new bool[rows] };
  bool *col_flags { new bool[cols] };
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
