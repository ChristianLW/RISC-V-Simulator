#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "instruction_decoding.h"
#include "instruction_execution.h"
#include "executor.h"

#define CASE_EXEC(opcode, func) case 0b##opcode: exec_##func(instruction); break

void executeInstruction(instruction_t instruction) {
	pc += 4;
	switch (instruction.opcode >> 2) {
		CASE_EXEC(01100, op); // OP
		CASE_EXEC(00000, load); // LOAD
		CASE_EXEC(11001, jalr); // JALR
		CASE_EXEC(11100, system); // SYSTEM
		CASE_EXEC(00100, op_imm); // OP-IMM
		CASE_EXEC(01000, store); // STORE
		CASE_EXEC(11000, branch); // BRANCH
		CASE_EXEC(00101, auipc); // AUIPC
		CASE_EXEC(01101, lui); // LUI
		CASE_EXEC(11011, jal); // JAL
	}
	registers[0] = 0;
}

void executeProgram(const char *testFile) {
	FILE *file = fopen(testFile, "rb");
	if (file == NULL) {
		perror("Failed to open executable binary");
		exit(1);
	}
	fseek(file, 0L, SEEK_END);
	long size = ftell(file); // Seek to end and get position
	fseek(file, 0L, SEEK_SET); // Rewind to start
	// Read the entire program into memory
	size_t read = fread(memory, 1, size, file);
	fclose(file);
	if (read != size) {
		fprintf(stderr, "Failed to read entire program into memory, managed to read %d/%d bytes", read, size);
		exit(1);
	}

	while (status == STATUS_RUNNING) {
		uint32_t instruction = *(uint32_t *)(memory + pc);
		instruction_t decoded = decodeInstruction(instruction);
		executeInstruction(decoded);
		if (pc >= size) status = STATUS_HALTED;
	}
}
