#include <stdexcept>

// None of that strictly defined/sized array based stack/queue stuff.
// Thats for when you know contraints, or have strict space limits.
template <class T>
class Stack {
private:
  struct node {
    T data;
    node* next = nullptr;
    node(T data, node* next) : data(data), next(next) {};
  };
  node* top_ = nullptr;
public:
  Stack() {}
  Stack(T seed[], size_t len) {
    for(size_t i = 0; i < len; ++i) {
      Push(seed[i]);
    }
  }
  void Push(T value) {
    node* ele = new node { value, top_ };
    top_ = ele;
  }
  bool IsEmpty() {
    return top_ == nullptr;
  }
  T Peek() {
    if (IsEmpty())
      throw std::runtime_error("Stack is empty");
    return top_->data;
  }
  T Pop() {
    if (IsEmpty())
      throw std::runtime_error("Stack is empty");
    node* popped = top_;
    T result = popped->data;
    top_ = popped->next;
    delete popped;
    return result;
  }
};
