#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0;
	for (int i = 0; i < 32; ++i) {
		res = (res << 1) + (n & 1);
		n >>= 1;
	}
	return res;
}

int main(int argc, char *argv[]) {
	uint32_t n = 6;
	printf("%u\n", n);
	printf("%u\n", reverseBits(n));
	return 0;
}