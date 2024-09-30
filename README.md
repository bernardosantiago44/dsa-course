# g++ cheat sheet
## Most common flags & commands
1) `-o <filename>` compiles and links files into an executable named `<filename>`. If not provided, the default filename is `a.out`.
Use `*.cpp` to compile multiple `.cpp` files into a single executable.
```bash
$ g++ main.cpp -o main
$ g++ *.cpp -o main
``` 
2) Show all warnings that may cause unexpected behavior `-Wall`
```bash
$ g++ -Wall main.cpp -o main
```
3) `--std=c++<##>` Specify the C++ version to compile the program, e.g. for using specific features of a C++ version.
```bash
$ g++ *.cpp -std=c++17 -o main
```
4) `-g` allows debugging for your program. Use this flag when using gdb or in the Vscode debugger.
```bash
$ g++ *.cpp -g
```
5) Run your binary in the terminal. For an executable named `main.exe`:
```bash
$ ./main.exe
```
## Examples

You can combine multiple flags in a single compile command. The order in which the flags appear is not important.

- Compile all files in my directory in an output file named `main.exe`, using `g++11`, allowing for debugging:
```bash
$ g++ *.cpp -o main.exe -std=c++11 -g
$ ./main.exe
```
