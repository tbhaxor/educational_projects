# Cafeteria Manegement Program
A simple project based on file handing in C

# Requirements
+ gcc v5+ installed

# How to Run
+ Change the `config.h` file
```cpp
// coder info
#define CODER "Gurkirat Singh"
#define SUBMITTED_TO "Mrs. Seema Shah"
#define INSTITUTION "MDU Rohtak"

// program config
#define MAIN_FILE_C "customer.bin"
#define MAIN_FILE_O "orders.bin"
#define TEMP_FILE_c "tmpc.bin"
#define TEMP_FILE_o "tmpo.bin"
#define CLEAR "clear" // change clear to cls if you are on windows
```

+ Building the program
```
$ gcc main.c config.h -o program
```

+ Running the program
```
$ ./program
```

**Note :** If you are on windows os then add `gcc.exe` to the enviroment path variable before compiling the program