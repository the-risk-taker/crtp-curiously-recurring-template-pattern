#include <iostream>

template <typename T>
struct Comparisons {
  bool operator== ( const Comparisons& other ) const {
    return !( static_cast<const T&> ( *this ) < static_cast<const T&> ( other ) || ( static_cast<const T&> ( other ) < static_cast<const T&> ( *this ) ) );
  };

  bool operator!= ( const Comparisons& other ) const { return !( *this == other ); }

  /* ... */
};

template <typename T>
struct BetterComparisons {
private:
  friend bool operator== ( const T& a, const T& b ) { return !( ( a < b ) || ( b < a ) ); };
  friend bool operator!= ( const T& a, const T& b ) { return !( a == b ); }

  /* ... */
};

struct Type : BetterComparisons<Type> {
  /* ... */
  Type ( int value ) : m_value{ value } {};
  bool operator<( const Type& other ) const { return m_value < other.m_value; };
  int m_value{ 0 };
};

int main() {
  Type a{ 0 };
  Type b{ 10 };

  std::cout << "(a == b): " << ( a == b ) << '\n';
  std::cout << "(a != b): " << ( a != b ) << '\n';

  a = 10;
  std::cout << "(a == b): " << ( a == b ) << '\n';
  std::cout << "(a != b): " << ( a != b ) << '\n';

  return 0;
}
