// Example based on code from: https://www.fluentcpp.com/2017/05/19/crtp-helper/

#include <iostream>

//                                        ↧ phantom type
template <typename T, template <typename> class crtpType>
struct Wrapper {
  T& instance() { return static_cast<T&> ( *this ); }
  T const& instance() const { return static_cast<T const&> ( *this ); }

private:
  Wrapper() {}
  friend crtpType<T>;
};

template <typename T>
struct InterfaceA : Wrapper<T, InterfaceA> {
  void methodA() { this->instance().methodA(); }
};

template <typename T>
struct InterfaceB : Wrapper<T, InterfaceB> {
  void methodB() { this->instance().methodB(); }
};

struct Implementation : InterfaceA<Implementation>, InterfaceB<Implementation> {
  void methodA() { std::cout << "Implementation::methodA()\n"; }
  void methodB() { std::cout << "Implementation::methodB()\n"; }
};

template <typename T>
void useA ( InterfaceA<T>& object ) {
  object.methodA();
}

template <typename T>
void useB ( InterfaceB<T>& object ) {
  object.methodB();
}

int main() {
  Implementation implementation;
  useA ( implementation );
  useB ( implementation );
}
