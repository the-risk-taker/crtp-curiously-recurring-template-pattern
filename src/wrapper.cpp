// Example based on code from: https://www.fluentcpp.com/2017/05/19/crtp-helper/

#include <iostream>

template <typename T>
struct Wrapper {
  T& instance() { return static_cast<T&> ( *this ); }
  T const& instance() const { return static_cast<T const&> ( *this ); }
};

template <typename T>
struct Interface : Wrapper<T> {
  void method() { this->instance().method(); }
};

struct Implementation : Interface<Implementation> {
  void method() { std::cout << "Implementation::method()\n"; } // this is needed!
};

template <typename T>
void use ( Interface<T>& object ) {
  object.method();
}

int main() {
  Implementation implementation;
  use ( implementation );
}
