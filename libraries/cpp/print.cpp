#include <iostream>
#include <unordered_map>

// Template function to print an unordered_map
template <typename K, typename V>
void printUnorderedMap(const std::unordered_map<K, V>& umap) {
    for (const auto& pair : umap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

// Template function to print a map
template <typename K, typename V>
void printMap(const std::map<K, V>& map) {
    for (const auto& pair : map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

// Template function to print any associative container
template <typename Container>
void printAssociativeContainer(const Container& container) {
    for (const auto& pair : container) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

// Template function to print vector
// Template function to print a vector
template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}
