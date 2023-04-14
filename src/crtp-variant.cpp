// Example based on code from: Software Architecture with C++ Adrian Ostrowski, Piotr Gaczkowski

#include <array>
#include <iostream>
#include <variant>

template <typename Item>
struct FancyItem {
  void appear_in_full_glory() { static_cast<Item*> ( this )->appear_in_full_glory(); }
};

struct RedHeels : FancyItem<RedHeels> {
  void appear_in_full_glory() { std::cout << "RedHeels reporting\n"; }
};

struct GoldenWatch : FancyItem<GoldenWatch> {
  void appear_in_full_glory() { std::cout << "GoldenWatch reporting\n"; }
};

using FancyVariant = std::variant<RedHeels, GoldenWatch>;

int main() {
  auto fancy_items = std::array{ FancyVariant{ RedHeels{} }, FancyVariant{ GoldenWatch{} } };

  for ( auto& item : fancy_items ) {
    std::visit ( []<typename T> ( FancyItem<T> i ) { i.appear_in_full_glory(); }, item ); // C++20
  }
}
