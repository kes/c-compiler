# Writing your own compiler
Following Nora Sandler's Writing a C Compiler (NoStarch Press)

Git submodles gtest, and Sandler's tests, are in the directory submods. If cloning
this repository, you'll need to do something like: 

```
git submodule init
git submodule update
```


Using CMake, to configure and build: 

```
mkdir build && cd build && cmake .. && cmake --build .
```

