// This is our minimal startup code (usually in _start)
asm("li sp, 0x100000"); // Set SP to 1 MB
asm("jal main");        // Call main
asm("mv a1, x10");      // Save return value in a1
asm("li a7, 10");       // Prepare ecall exit
asm("ecall");           // Now the simulator should stop

int recursive(int iter) {
	if (iter < 1)
		return 1;
	return recursive(iter - 1) + 1;
}

int main() {
	return recursive(100);
}
