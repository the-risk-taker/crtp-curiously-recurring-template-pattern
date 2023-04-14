template <class T>
class Base {
  void doSomething() {
    T& derived = static_cast<T&> ( *this ); // I can access derived methods now, yeah 🎉
    // derived.something();
  }
};

class Derived : public Base<Derived> {
  // ...
};
