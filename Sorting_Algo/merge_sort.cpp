// Author: David Kanekanian
// This algorithm requires at least C++14.

#include <algorithm>  // std::transform
#include <iterator>  // std::back_inserter
#include <vector>  // std::vector


template<class T, class Compare>
std::vector<T> merge_sort(const std::vector<T>& to_sort, Compare cmp) {
    // Merge two sorted arrays component.
    auto merge_ = [&cmp](
        auto a_first, auto a_last,
        auto b_first, auto b_last, auto ret_first
    ) {
        auto a = a_first;
        auto b = b_first;
        auto ret = ret_first;
        const auto a_len = static_cast<std::size_t>(std::distance(a_first, a_last));
        const auto b_len = static_cast<std::size_t>(std::distance(b_first, b_last));
        while (a < a_last && b < b_last) {
            // Add best element between both arrays.
            if (cmp(*a, *b)) {
                *ret = *a;
                ++a;
            } else {
                *ret = *b;
                ++b;
            }
            ++ret;
        }
        // Add remaining elements.
        while (a < a_last) { *ret = *a; ++a; ++ret; }
        while (b < b_last) { *ret = *b; ++b; ++ret; }
    };

    // Turn to_sort into groups of one.
    std::vector<std::vector<T>> groups;
    groups.reserve(to_sort.size());
    std::transform(
        begin(to_sort), end(to_sort), std::back_inserter(groups),
        [](const auto& el) { return std::vector<T>{ {el} }; }
    );

    while (groups.size() > 1) {
        // Counters needed to be declared in this scope.
        std::size_t i{0}, j{0};
        for (; i + 1 < groups.size(); i += 2, j++) {
            // Merge pairs of groups and store at the beginning.
            const auto len = groups[j].size();
            merge_(begin(groups[i]), end(groups[i]),
                   begin(groups[i + 1]), end(groups[i + 1]),
                   std::back_inserter(groups[j]));
            groups[j].erase(begin(groups[j]), begin(groups[j]) + len);
        }
        // Remove merged groups.
        groups.erase(begin(groups) + j, end(groups) - (groups.size() % 2));
    }

    return groups[0];
}

// Demo
#include <iostream>

int main() {
    std::vector<int> v{5, 3, 6, 2, 7};
    auto v1 = merge_sort(v, [](auto a, auto b){ return a < b; });
    for (const auto& el : v1) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

