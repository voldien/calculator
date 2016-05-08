#include<stdio.h>
#include"solve.h"
#include<getopt.h>




int main(int argc, char** argv){
	long value;

	int c;
	static struct option longoption[] = {
		{"","","",""},
		{"","","",""},
		{NULL, NULL, NULL, NULL}
	};
	while( ( c = getopt(argc, argv, "v:h:i:e:a") ) != EOF){

		switch(c){
			case 'v':
			break;
			case 'h':
			break;
			case 'i':
			break;
			case 'e':
			break;
			case 'a':
			break;
			default:
			break;
		}

	}

	//solvearithmetic(argv[1],&value);

	double answer = solvearithmetic("(2 + 4) * (32 / 32  + 32)", &value);

	printf("answer: %f\n", (float)answer);
	return EXIT_SUCCESS;
}
