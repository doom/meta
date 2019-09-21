/*
** Created by doom on 19/01/19.
*/

#include <tuple>
#include <variant>
#include <type_traits>
#include <vector>
#include <meta/utils/rebind.hpp>
#include <meta/sequence/list.hpp>

using t = std::tuple<int, char, bool>;
using v = doom::meta::rebind<t, std::variant>;
static_assert(std::is_same_v<v, std::variant<int, char, bool>>);

using lst = doom::meta::list<int, std::allocator<int>>;
using vec = doom::meta::rebind<lst, std::vector>;
static_assert(std::is_same_v<vec, std::vector<int, std::allocator<int>>>);
