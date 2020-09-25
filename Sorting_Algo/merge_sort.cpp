// Merge Sort Algorithm
// Author: David Kanekanian
// This implementation requires at least C++11 due to lambda.
// But the demo requires at least C++17 due to template deductions.


#include <algorithm>  // std::transform
#include <iterator>  // std::back_inserter
#include <vector>  // std::vector


template<class T, class Compare>
std::vector<T> merge_sort(const std::vector<T>& to_sort, Compare cmp) {
    // Merge two sorted arrays component.
    auto merge_ = [&cmp](const std::vector<T>& a, const std::vector<T>& b, std::vector<T>& out) {
        std::size_t i{0}, j{0};
        std::size_t size_a{a.size()}, size_b{b.size()};
        while (i < size_a && j < size_b) {
            // Add best element between both arrays.
            out.push_back(cmp(a[i], b[j]) ? a[i++] : b[j++]);
        }
        // Add remaining elements.
        while (i < size_a) { out.push_back(a[i++]); }
        while (j < size_b) { out.push_back(b[j++]); }
    };

    // Turn to_sort into groups of one.
    std::vector<std::vector<T>> groups;
    groups.reserve(to_sort.size());
    std::transform(
        begin(to_sort), end(to_sort), std::back_inserter(groups),
        [](const T& el) { return std::vector<T>{ {el} }; }
    );

    while (groups.size() > 1) {
        // Counters needed to be declared in this scope.
        std::size_t i{0}, j{0};
        for (; i + 1 < groups.size(); i += 2, j++) {
            // Merge pairs of groups and store at the beginning.
            const auto len = groups[j].size();
            merge_(groups[i], groups[i + 1], groups[j]);
            groups[j].erase(begin(groups[j]), begin(groups[j]) + len);
        }
        // Remove merged groups.
        groups.erase(begin(groups) + j, end(groups) - (groups.size() % 2));
    }

    return groups[0];
}

// Demo
// Demo requires at least C++17
// #include <iostream>
//
// int main() {
//     std::vector v{5, 3, 6, 2, 7};
//     auto v1 = merge_sort(v, [](auto a, auto b){ return a < b; });
//     for (const auto& el : v1) {
//         std::cout << el << " ";
//     }
//     std::cout << '\n';
// .   // Output: 2 3 5 6 7
// }
