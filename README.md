# CTCI-CPP14
Cracking the Coding Interview 5th edition solutions implemented in modern C++14.

## Solutions Implemented

Brief but complete questions are above each solution in the code

#### Strings and Arrays

- [x] 1.1 `bool OnlyUniqueChars(std::string*)`
- [x] 1.2 `void Reverse(char*)`
- [x] 1.5 `std::string BadCompression(std::string)`
- [x] 1.6 `template<class Pixel> void RotateImg(Pixel*, int)`
- [x] 1.7 `template <size_t rows, size_t cols> void ZeroIntercepts(int (&matrix)[rows][cols])`

#### Linked Lists

- [x] Structure implementation
- [x] 2.1 `void DeleteDupNodes(SinglelyLinkedList*)`
- [x] 2.2 `node* FromEnd(SinglelyLinkedList*, int)`
- [x] 2.3 `void DeleteNode(node*)`
- [x] 2.4 `void PartitionAround(SinglelyLinkedList**, int)`
- [x] 2.5 `SinglelyLinkedList SumReveredDigits(SinglelyLinkedList*, SinglelyLinkedList*)`
- [x] 2.6 `node* FindFirstOfCircular(SinglelyLinkedList*)`
- [x] 2.7 `bool IsPalindrome(SinglelyLinkedList*)`

#### Stacks and Queues

- [ ] Stack implementation
- [ ] Queue implementation
- [ ] 3.1 `TripleStack::TripleStack(int[], int)`
- [ ] 3.2 `node* Stack::Min()`
- [ ] 3.3 `SetOfStacks::SetOfStacks(int)`
- [ ] 3.3 `node* SetOfStacks::PopAt(int)`
- [ ] 3.4 Towers Of Hanoi
- [ ] 3.5 `class MyQueue` with two stacks
- [ ] 3.6 `SortAsc(Stack*)`
- [ ] 3.7 `class AdoptionQueue`


## Building
Build however you like, this is meant more as a web reference. Testing suite is in src as a precompiled header. If using xcode but not the unignored project settings, ensure only main.cpp is chose as a compile sourse in the build phases.

## Testing
Catch2 is used for testing in TDD style. Catch2's main is used, compiling/executing the problem will automatically run the test suite. (Tip: run with -s to should every test case and its result in the console );

## Folder structure

```
CTCI
|-- src/
|    | # Class files implementing solutions organized by chapter
|-- test/
|    | catch.hpp- Testing suite precompiled header
|    | # Test files testing solutions*
|-- main.cpp
```
