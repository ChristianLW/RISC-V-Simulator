#ifndef STATE_H
#define STATE_H

#include <stdint.h>

typedef enum {
	STATUS_RUNNING,
	STATUS_HALTED,
} status_t;

extern uint8_t memory[];
extern int32_t registers[];
extern uint32_t pc;
extern status_t status;

#endif
