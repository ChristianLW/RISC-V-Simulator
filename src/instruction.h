#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

typedef struct {
	uint8_t opcode;
	uint8_t rd;
	uint8_t rs1;
	uint8_t rs2;
	uint8_t funct3;
	uint8_t funct7;
	uint32_t imm;
} instruction_t;

#endif
