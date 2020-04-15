unordered_map has no rbegin() nor rend()
unordered_map key must be hashable

Consider map instead



## Longest Palindromic Substring
f(i; j) =   true; i = j
            S[i] == S[j]; j = i + 1
            S[i] == S[j] && f(i+1; j-1); j > i + 1
    
## Regular Expression Matching

## Wildcard Matching

# split strings by char delimeter

```cpp
        std::string token;
        char delimeter;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimeter)) {
            // handle token
        }
```


# split strings by space
```cpp
        std::string token;
        std::stringstream tokenStream(str);
        while (tokenStream >> token) {
            // handle token
        }
```

# middle of LinkList

0       1       2       3       4       5       6       7   nullptr
fast            fast            fast            fast        fast 
slow    slow    slow    slow    slow   



# The prototype of the priority_queue template class is as follows:

```cpp
template <
   class Type, 
   class Container=vector<Type>,
   class Compare=less<typename Container::value_type> 
>
class priority_queue
```

# priority_queue with struct
```cpp
// program in c++ to use priority_queue with structure 
  
#include <iostream> 
#include <queue> 
using namespace std; 
#define ROW 5 
#define COL 2 
  
struct Person { 
    int age; 
    float height; 
    
    Person(int age, float height)
        : age(age), height(height) { } 
}; 
  
// this is an strucure which implements the 
// operator overlading 
struct CompareHeight { 
    bool operator()(Person const& p1, Person const& p2) { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.height < p2.height; 
    } 
}; 


int main() { 
    priority_queue<Person, vector<Person>, CompareHeight> Q; 
  
    // When we use priority_queue with  structure 
    // then we need this kind of syntax where 
    // CompareAge is the functor or comparision function 
    float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },  
                    { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 
  
    for (int i = 0; i < ROW; ++i) { 
        Q.push(Person(arr[i][0], arr[i][1])); 
  
        // insert an object in priority_queue by using 
        // the Person strucure constructor 
    } 
  
    while (!Q.empty()) { 
        Person p = Q.top(); 
        Q.pop(); 
        cout << p.age << " " << p.height << "\n"; 
    } 
    return 0; 
} 

// Output :
// 33 6.1
// 20 6
// 23 5.6
// 30 5.5
// 25 5

```


# priority_queue with class

```cpp
class Person { 
public: 
    int age; 
    float height; 
  
    // this is used to initialize the variables of the class 
    Person(int age, float height) 
        : age(age), height(height) { } 
}; 
  
// we are doing operator overloading through this 
bool operator<(const Person& p1, const Person& p2) { 
  
    // this will return true when second person  
    // has greater height. Suppose we have p1.height=5  
    // and p2.height=5.5 then the object which 
    // have max height will be at the top(or  
    // max priority) 
    return p1.height < p2.height; 
} 

int main() { 
  
    priority_queue<Person> Q; 
  
    float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },  
               { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 
  
    for (int i = 0; i < ROW; ++i) { 
  
        Q.push(Person(arr[i][0], arr[i][1])); 
  
        // insert an object in priority_queue by using 
        // the Person class constructor 
    } 
  
    while (!Q.empty()) { 
        Person p = Q.top(); 
        Q.pop(); 
  
        cout << p.age << " " << p.height << "\n"; 
    } 
    return 0; 
} 
  
```