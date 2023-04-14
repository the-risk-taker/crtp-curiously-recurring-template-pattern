// template <typename T>
// struct Base {};

template <typename T>
class Base {
public:
  // ...
private:
  Base() = default;
  friend T;
};

struct Derived1 : Base<Derived1> { // 😎
};

struct Derived2 : Base<Derived1> { // undefined behaviour 😥
};

int main() {
  Derived1 d1;
  //   Derived2 d2;
}
