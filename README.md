# CTCI-CPP14
Cracking the Coding Interview 5th edition solutions implemented in modern C++14.

## Solutions Implemented

Brief but complete questions are above each solution in the code

#### Strings and Arrays

- [ ] 1.1 `void only_unique_chars(std::string*)`
- [x] 1.2 `void reverse(char*)`
- [ ] 1.3 `boolean is_permutation(std::string*, std::string*)`
- [x] 1.5 `std::string bad_compression(std::string)`
- [x] 1.6 `template<class Pixel> void rotate_img(Pixel*, int)`
- [x] 1.7 `template <size_t rows, size_t cols> void zero_intercepts(int (&matrix)[rows][cols])`

#### Linked Lists

- [x] Structure implementation
- [x] 2.1 `void delete_dup_nodes(SinglelyLinkedList*)`
- [x] 2.2 `node* from_end(SinglelyLinkedList*, int)`
- [x] 2.3 `void delete_node(node*)`
- [x] 2.4 `void partition_around(SinglelyLinkedList**, int)`
- [x] 2.5 `SinglelyLinkedList sum_revered_digits(SinglelyLinkedList*, SinglelyLinkedList*)`
- [x] 2.6 `node* find_first_of_circular(SinglelyLinkedList*)`
- [x] 2.7 `boolean is_palindrome(SinglelyLinkedList*)`



## Building
Build however you feel comfortable, this is meant more as a web reference. If using xcode but not the unignored project settings, ensure only main.cpp is chose as a compile sourse in the build phases.

## Testing
Currently, 'tests' are user handled by means of logging and checking to see if solution is working.

**Implementation of testing framework to unit test properly with multiple cases WIP**

## Folder structure

```
CTCI
|-- src/
|    | # Class files implementing solutions organized by chapter
|-- test/
|    | # Test files testing solutions*
|-- main.cpp
```
