#include <iostream>

template <typename T>
struct counter {
  static inline int objects_created = 0;
  static inline int objects_alive = 0;

private:
  counter() {
    ++objects_created;
    ++objects_alive;
  }

  counter ( const counter& ) {
    ++objects_created;
    ++objects_alive;
  }

  ~counter() { --objects_alive; }

  friend T;
};

class X : counter<X> {};

template <typename T>
void template_method ( T& object ) {}

int main() {
  X x;
  {
    X a = x;
    X b;
  }

  std::cout << "created: " << counter<X>::objects_created << " alive: " << counter<X>::objects_alive << '\n';
}
