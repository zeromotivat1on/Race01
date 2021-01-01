#include "../inc/calculator.h"

int main(int argc, char **argv){
	if(argc != 5){
		mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
		exit(0);
	}

	int op = 0;
	char operations[4] = {'+', '-', '*', '/'};
	//check operation
	if(mx_strlen(mx_strtrim(argv[2])) != 1){
		mx_printerr("Invalid operation: ");
		mx_printerr(argv[2]);
		mx_printerr("\n");
		exit(0);
	}
	else{
		char temp_op = *mx_strtrim(&argv[2][0]);
		bool found = false;
		for(int k = 0; k < 4; ++k){
			if(temp_op == operations[k]){
				op = operations[k];
				found = true;
			}
			else if(temp_op == '?'){
				op = '?';
				found = true;
			}
		}
		if(!found){
			mx_printerr("Invalid operation: ");
			mx_printerr(argv[2]);
			mx_printerr("\n");
			exit(0);	
		}
	}
	// check operands
	for(int i = 1; i < argc; ++i){
		char *temp = mx_strtrim(argv[i]);
		for(int j = 0; j < mx_strlen(temp); ++j){
			// check operands
			if(i != 2){
				if(temp[j] == '?') continue;
				if(!mx_isdigit(temp[j])){
					if(i == 4){
						mx_printerr("Invalid result: ");
						mx_printerr(argv[i]);
						mx_printerr("\n");
						exit(0);
					}
					mx_printerr("Invalid operand: ");
					mx_printerr(argv[i]);
					mx_printerr("\n");
					exit(0);
				}
			}
		}
	}

	char *args[3] = {mx_strtrim(argv[1]),mx_strtrim(argv[3]),mx_strtrim(argv[4])};
	for(int i = 0; i < 3; ++i) printf("args[%d]:%s\n", i, args[i]);

	switch (op){
		case '+':
			add(args);
			break;
		case '-':
			printf("-\n");
			break;
		case '*':
			printf("*\n");
			break;
		case '/':
			if(mx_strcmp(args[1], "0") == 0){
				mx_printerr("\n");
				exit(0);
			}
			else {
				printf("/\n");
			}
			break;
		case '?':
			printf("?\n");
			break;
	}
}

