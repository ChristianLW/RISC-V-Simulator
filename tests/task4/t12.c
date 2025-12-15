// This is our minimal startup code (usually in _start)
asm("li sp, 0x100000"); // Set SP to 1 MB
asm("jal main");        // Call main
asm("mv a1, x10");      // Save return value in a1
asm("li a7, 10");       // Prepare ecall exit
asm("ecall");           // Now the simulator should stop

int sum(int arr[], int len) {
	int _sum = 0;
	for (int i = 0; i < len; i++)
		_sum += arr[i];
	return _sum;
}

int main() {
	int len = 100;
	int arr[len];
	for (int i = 0; i < len; i++)
		arr[i] = i;
	return sum(arr, len);
}
