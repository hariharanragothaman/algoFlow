#include <iostream>
#include <unordered_map>

// Template function to print an unordered_map
template <typename K, typename V>
void printUnorderedMap(const std::unordered_map<K, V>& umap) {
    for (const auto& pair : umap) {
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

// Template function to print a 2D vector
template<typename T>
void print2DVector(const std::vector<std::vector<T>>& vec) {
    for (const auto& innerVec : vec) {
        for (const auto& element : innerVec) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    return 0;
}
