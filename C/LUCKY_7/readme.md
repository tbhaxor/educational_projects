# Lucky 7 Game
This is the game for demonstrating random function in `stdlib`

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
#define TRIES 3
#define MULTIPLY_ON_7 3
#define MULTIPLY_ON_CORRECT 2
#define MIN_BET 100

#define CLEAR "clear"   // change clear to cls if you are on windows
```

+ Building the program
```
$ gcc main.c config.h -o program
```

+ Running the program
```
$ program
```

**Note :** If you are on windows os then add `gcc.exe` to the enviroment path variable before compiling the program