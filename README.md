# TVM
## What is TVM
TVM (Tiny Virtual Machine) is a compact virtual machine. Having its no less compact assembler "nom". TVM can be used to simulate a simple computer. TVM has 4096 bytes (4 KB) of memory and eight registers with 256 bytes of memory.
> Despite the non-printing characteristics, the memory and registers will be increased in the future.

## TVM programming
At the moment, programs under TVM can be written in two ways: the first is TA0 (no longer supported, it's legacy) . Simple built-in assembler for TVM. There is also a second way, it is a programming language "nom", similar to TA0 but does not require binding to gcc. The nom language is still in development, so bugs are not excluded when using it.

## Running programs on TVM
TVM is also able to run the files .ncp (it's own standard files for TVM).
> To create an ncp file, you need to include the ncpgen header file.h. Then you need to use a utility ncprun.c (compile it), this utility takes the file name as command line arguments.
> It can also accept the-m flag then, among other things, the contents of the ncp file will be displayed.

## For more information about TVM, read the documentation in the TVM/docs/en or rus directory
Use build to compile the 

> build.exe

or otherwise, if the application does not fit your platform, use a different method:

> gcc nom.c -o nom.exe gcc ncprun.c -o run.exe
