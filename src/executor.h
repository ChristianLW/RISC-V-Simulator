#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "instruction.h"
#include "memory.h"

void executeInstruction(instruction_t instruction);
void executeProgram(const char *testFile);

#endif
