# Clang-Param-Analyzer

A program to analyze C++ source code and detects functions or methods whose parameter count is more than three.
`Note: You need at least 150 GB of disk space to build and work on this project.`
## Requirements
###### cmake (version 3.6 or higher) 
###### clang and llvm

### Build Clang and llvm
***To build clang and llvm, follow the instructions below or you can visit*** https://clang.llvm.org/get_started.html
1. Check out LLVM:
* Change directory to where you want the llvm directory placed.
* svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm
2. Check out Clang:
* cd llvm/tools
* svn co http://llvm.org/svn/llvm-project/cfe/trunk clang
* cd ../..
3. Check out extra Clang tools: (optional)
* cd llvm/tools/clang/tools
* svn co http://llvm.org/svn/llvm-project/clang-tools-extra/trunk extra
* cd ../../../..
4. Check out Compiler-RT (optional):
* cd llvm/projects
* svn co http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt
* cd ../..
5. Build LLVM and Clang:
* mkdir build 
* cd build
* cmake -G "Unix Makefiles" ../llvm
* make
* sudo make install (**takes around 5 to 6 hours depending on the system**)

## How to run my code?
```
$ cd ~/<your_clang_llvm_directory>/llvm/tools/clang/tools/extra
$ git clone https://github.com/AkarshRK/Clang-Param-Analyzer.git
$ cd ~/<your_clang_llvm_directory>/build
$ make
```

If the make command in the last step is taking a lot of time, then you can try building and compiling your tool directly from the following commands:
```
$ cd ~/<your_clang_llvm_directory>/build
$ make -f CMakeFiles/Makefile2 param-analyzer
$ make -f tools/clang/tools/libclang/CMakeFiles/install-libclang-stripped.dir/build.make tools/clang/tools/libclang/CMakeFiles/install-libclang-stripped.dir/build
```

Now you can run your tool on any C++ code as follows:
Copy the above "Param.cpp" into build directory.
```
$ cd ~/<your_clang_llvm_directory>/build
$ bin/param-analyzer Param.cpp
<---Warning--->
"add" has more than three parameters. 
```

## The above project was run on a system with following configurations or settings:
* Operating system: Linux Mint 18.3 "Sylvia" - Cinnamon (64-bit)
* Processor: Intel® Core™ i7-7500U Processor  2.70GHz 2 Core(s)
* Memory (RAM): 15.5 GB












