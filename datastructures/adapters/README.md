### Intro to Container Adapters

1. C++ has with std::stack, std::queue and std::priority_queue three special sequential containers. I guess, most of you know these classic data structures from your education. 
2. The adaptors for containers 
   1. Support a reduced interface for existing sequential containers, 
   2. Can not be used with algorithms of the Standard Template Library
   3. Are class templates which are parametrised by their data type and their container (std::vector, std::list and std::deque), 
   4. Use by default std::deque as the internal sequential container:

```c++
template <typename T, typename Container= deque<T>> 
class stack;
```
