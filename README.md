# TVM
## What is TVM
TVM (Tiny Virtual Machine) is a compact virtual machine. Having its no less compact assembler TA0. TVM can be used to simulate a simple computer. TVM has 4096 bytes (4 KB) of memory and eight registers with 256 bytes of memory.
> Despite the non-printing characteristics, the memory and registers will be increased in the future.

## TVM programming
TVM at the moment prolongiruetsa only one way - TA0. TA0 is the native simplified assembler of TVM.
> To use a TA is required to include the header file tvmAsm.h.

## Running programs on TVM
TVM is also able to run the files .ncp (it's own standard files for TVM).
> To create an ncp file, you need to include the ncpgen header file.h. Then you need to use a utility ncprun.c (compile it), this utility takes the file name as command line arguments.
> It can also accept the-m flag then, among other things, the contents of the ncp file will be displayed.
