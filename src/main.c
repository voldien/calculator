#include<stdio.h>
#include"solve.h"


int main(int argc, char** argv){
	long value;

	//solvearithmetic(argv[1],&value);

	solvearithmetic("(2 + 4) * (32 /32  + 32)",&value);

	printf("answer: %d\n", value);
	return 0;
}
