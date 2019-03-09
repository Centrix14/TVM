#ifndef TVMASM_H_INCLUDED
#define TVMASM_H_INCLUDED

/*
tvmAsm.h v0.3.1
Заголовочный файл ассемблера TVM / TVM assembler header file
08.03.2019
by Centrix
*/

#include <stdio.h>
#include <string.h>
#include "tsl.c"
#include "ngl.c"
#include "main.h"

#define $CRG {memory[memIndx++] = CRG;}
#define $CRC {memory[memIndx++] = CRC;}
#define $PRG {memory[memIndx++] = PRG;}
#define $PRC {memory[memIndx++] = PRC;}
#define $CRGI {memory[memIndx++] = CRG;} {memory[memIndx++] = STDI;} memory[memIndx++] = 
#define $CRCI {memory[memIndx++] = CRC;} {memory[memIndx++] = STDI;} memory[memIndx++] = 
#define $PRCI {memory[memIndx++] = PRC;} {memory[memIndx++] = STDI;} memory[memIndx++] = 
#define $PRGI {memory[memIndx++] = PRG;} {memory[memIndx++] = STDI;} memory[memIndx++] = 
#define $CRGA {memory[memIndx++] = CRG;} {memory[memIndx++] = STDA;} memory[memIndx++] = 
#define $CRCA {memory[memIndx++] = CRC;} {memory[memIndx++] = STDA;} memory[memIndx++] = 
#define $PRGA {memory[memIndx++] = PRG;} {memory[memIndx++] = STDA;} memory[memIndx++] = 
#define $PRCA {memory[memIndx++] = PRC;} {memory[memIndx++] = STDA;} memory[memIndx++] = 
#define $JUMP {memory[memIndx++] = GJP;} memory[memIndx++] = 
#define $COM {memory[memIndx++] = COM;} memory[memIndx++] = 
#define $SMEM(x, value) {memory[x] = value;}
#define $GMEM(x) {memory[x];} 
#define $GREG(x, y) reg[x][y] 

#define _$STDI {memory[memIndx++] = STDI;}
#define _$STDA {memory[memIndx++] = STDA;}
#define _$DATA memory[memIndx++] =
#define _$COND memory[memIndx++] = 

#define _RESTART {memory[memIndx++] = RESTART;}
#define _QUIT {memory[memIndx++] = QUIT;}
#define _CLEAR {memory[memIndx++] = CLEAR;} memory[memIndx++] = 
#define _MAIN {memory[memIndx++] = MAIN;}
#define _POINT {memory[memIndx++] = JPT;} memory[memIndx++] = 
#define _EB {memIndx++;}
#define _END {memory[memIndx] = end;}
#define _RUN {memInter();}
#define _toNCP(name) {strcpy(filename, name);} {ncpGen();}
#define _COM(name) _RUN _toNCP(name)
#define _DEB {memory[memIndx++] = DEB;}

#endif // TVMASM_H_INCLUDED
