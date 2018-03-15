#include <stdexcept>

// None of that strictly defined/sized array based stack/queue stuff.
// Thats for when you know contraints, or have strict space limits.
// On the rule of 3... no copies implemented to keep this simple but
// complete to the challenge of a basic stack with req members.
template <typename T>
class Stack {
private:
  struct node {
    T data;
    node* next = nullptr;
  };
  node* top_ = nullptr;
public:
  Stack() {}
  Stack(T seed[], size_t len) {
    for(size_t i = 0; i < len; ++i) {
      push(seed[i]);
    }
  }
  ~Stack() {
    while (top_ != nullptr) {
      node* next = top_->next;
      delete top_;
      top_ = next;
    }
  }
  void push(T const& value) {
    // const& to avoid a heavy copy of a more complex type stack
    node* ele = new node { value, top_ };
    top_ = ele;
  }
  const bool isEmpty() {
    return top_ == nullptr;
  }
  const T &top() {
    if (isEmpty())
      throw std::runtime_error("Stack is empty");
    return top_->data;
  }
  void pop() {
    if (isEmpty())
      return;
    node* popped = top_;
    top_ = popped->next;
    delete popped;
  }
};
