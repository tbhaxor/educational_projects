# Library Book Record Manager
Program in `c++` implementing file handling (binary)

# Requirements
+ g++ v5 or greater

# How to Run
+ First of all modify details according to your taste in _config.h_ in following lines
```
// coder info
#define CODER "Gurkirat Singh"
#define SUBMITTED_TO "Mrs. Seema Shah"
#define INSTITUTION "MDU Rohtak"
```
+ In windows change `#define CLEAR "clear"` to `#define CLEAR "cls"`
+ Build the program
> Linux

```
g++ program.cpp library.cpp book.cpp -o program
```

> Windows  (only if g++ is added in %path%)

```
g++ program.cpp library.cpp book.cpp -o program
```

+ Launching the application
> Linux

```
./program
```

> Windows

```
program
```
