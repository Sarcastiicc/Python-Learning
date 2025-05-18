# Python Learning

## Package and module

### Module
A single module is equevalant to a single .py file for Python

### Package
A package is comprised of one or mutiple .py file(s)
Users have to manully define the package within .py files

### import
Normally there are 2 ways to use `import`
- `import <packageName>.<componentName>`
    - We can use the component directly without specifying the package name.
- `import <packageName>`
    - The package name is required to be specified when using the components.


**Note**
The imported modules are executed followed by the importing .py file.

---

# Basic Datatype

- List 
    A container with variable length (elements with different datatypes are permitted).
    - append()
    - remove()
- Tuple
    A container with fixed length (elements with different datatypes are permitted).
    **Cannot** be modified after initialization.
- Set
    Equivalent to `unordered_set` in C++
- Dictionary
    Equivalent to `unordered_map` in C++, but keys with different datatypes are permitted.
    ```
    my_dict = {
                  'key1' : 'value1',
                  'key2' : 'value2',
                  local_var : 'value3'
    	      }
    
    ```
---
