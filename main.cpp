
#if __cplusplus < 201700L
# error Needs C++17 or greater
#endif
#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <tuple>
#include <type_traits>
#include <algorithm>
#include <iterator>

using namespace std::string_literals;

namespace a::b::c {
  inline std::string_view constexpr str { "hello" };
}

template<class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args) {
  return { sizeof ...(T), (args + ...) };
}

auto main(int argc, char const * argv[]) -> decltype(argc) {
  std::cout << "C++ " << __cplusplus << std::endl;

  auto [iNumbers, iSum] { sum(1u, 2, 3u, 4, 5u) };
  std::cout << a::b::c::str << ' '
            << iNumbers << ' '
            << iSum << '\n';

  // deduction guide for array creation
  std::array ary { 1u, 2U, 3u, 4u, 5u, };

  auto x(ary[0]);
  std::cout << std::size(ary) << ": ";
  std::copy(ary.cbegin(), ary.cend(),
            std::ostream_iterator<decltype(x)>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
