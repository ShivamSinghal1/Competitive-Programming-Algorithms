// Author: David Kanekanian
// This algorithm requires at least C++14.

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>


template<class T>
std::vector<T> merge_sort(const std::vector<T>& to_sort) {
    // Merge two sorted arrays component.
    auto merge_ = [](const std::vector<T>& a, const std::vector<T>& b) {
        std::vector<T> ret;
        std::size_t i{0}, j{0};
        while (i < a.size() && j < b.size()) {
            // Add best element between both arrays.
            ret.push_back(a[i] < b[j] ? a[i++] : b[j++]);
        }
        // Add remaining elements.
        while (i < a.size()) { ret.push_back(a[i++]); }
        while (j < b.size()) { ret.push_back(b[j++]); }
        // Return merged array.
        return ret;
    };

    // Turn to_sort into groups of one.
    std::vector<std::vector<T>> groups;
    groups.reserve(to_sort.size());
    std::transform(
        begin(to_sort), end(to_sort), std::back_inserter(groups),
        [](const auto& el) { return std::vector<T>{ {el} }; }
    );

    while(groups.size() > 1) {
        // Counters needed to be declared in this scope.
        std::size_t i{0}, j{0};
        for (; i + 1 < groups.size(); i += 2, j++) {
            // Merge pairs of groups and store at the beginning.
            groups[j] = merge_(groups[i], groups[i + 1]);
        }
        // Remove merged groups.
        groups.erase(begin(groups) + j, end(groups) - (groups.size() % 2));
    }

    return groups[0];
}

int main() {
    std::vector<int> v{5, 3, 6, 2, 7};
    auto v1 = merge_sort(v);
    for (const auto& el : v1) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

