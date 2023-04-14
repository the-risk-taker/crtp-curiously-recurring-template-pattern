#include <iostream>

template <class T>
struct Interface {
  void method() { static_cast<T*> ( this )->method(); }
};

struct Implementation : Interface<Implementation> {
  void method() { std::cout << "Implementation::method()\n"; }
};

template <typename T>
void use ( Interface<T>& object ) {
  object.method();
}

template <typename T>
void template_method ( T& object ) {
  object.method();
}

int main() {
  Implementation implementation;
  use ( implementation );

  template_method ( implementation );
}
