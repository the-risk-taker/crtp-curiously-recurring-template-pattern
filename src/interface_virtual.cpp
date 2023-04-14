#include <iostream>

struct Interface {
  ~Interface() = default;
  virtual void method() = 0;
};

struct Implementation : Interface {
  void method() final { std::cout << "Implementation::method()\n"; }
};

void use ( Interface& object ) { object.method(); }

int main() {
  Implementation implementation;
  use ( implementation );
}
