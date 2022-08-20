
### Why we need to use the ```use namespace std;```

* namespace are a c++ feature that prevent name confilcting by putting symbol 
```
    namespace n1 {
        fun A()
        {

        }
    }
    namespace n2 {
        fun A()
        {

        }
    }    
```
* evrything in c++ standard lib is under std name space ,which is why we often used the syntax 
    ```std::vector<int> v```

### STL has four components
* Algorithms
* Containers
* Functions
* Iterators

#### Algorithms
    1. sort(first_iterator, last_iterator) – To sort the given vector.
    2. reverse(first_iterator, last_iterator) – To reverse a vector.
    3. *max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
    4. *min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
    5.  accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements
    6.  count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
    7.  find(first_iterator, last_iterator, x) – Returns an iterator to the first occurrence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector. 
    8.  binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not.
    9.  lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which         has a value not less than ‘x’.
    10. upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last)                  which has a value greater than ‘x’. 
### Containers
Containers or container classes store objects and data. There are in total seven standard “first-class” container classes and three container adaptor classes and only seven header files that provide access to these containers or container adaptors.
* Sequence Containers: implement data structures which can be accessed in a sequential manner.
    * vector
    * list
    * deque
    * arrays
* Container Adaptors : provide a different interface for sequential containers.
    * queue
    * priority_queue
    * stack
* Associative Containers : implement sorted data structures that can be quickly searched (O(log n) complexity).
    * set
    * multiset
    * map
    * multimap
* Unordered Associative Containers : implement unordered data structures that can be quickly searched
    * unordered_set
    * unordered_multiset 
    * unordered_map 
    * unordered_multimap 
### Utility
* Pair

    
    

