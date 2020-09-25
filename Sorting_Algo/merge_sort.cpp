// Author: David Kanekanian
// This algorithm requires at least C++14.

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>


template<class T>
std::vector<T> merge_sort(const std::vector<T>& to_sort) {
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
    for (auto el: merge_({ 1, 2}, {3, 4})) std::cout<<el <<' ';
return {};

}

int main() {
    std::vector<int> v{5, 3, 6, 2, 7};
    auto v1 = merge_sort(v);
    for (const auto& el : v1) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

