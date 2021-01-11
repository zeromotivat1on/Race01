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
	// check operands and result
	for(int i = 1; i < argc; ++i){
		char *temp = mx_strtrim(argv[i]);
		if(temp == NULL || mx_strcmp(argv[i], "") == 0){
			if(i == 4) mx_printerr("Invalid result: ");
			else mx_printerr("Invalid operand: ");
			mx_printerr(argv[i]);
			mx_printerr("\n");
			exit(0);
		}
		for(int j = 0; j < mx_strlen(temp); ++j){
			if(i != 2){
				if(temp[j] == '?') continue;
				else if(!mx_isdigit(temp[j])){
					if(i == 4) mx_printerr("Invalid result: ");
					else mx_printerr("Invalid operand: ");
					mx_printerr(argv[i]);
					mx_printerr("\n");
					exit(0);
				}
			}
		}
	}
	//array which consists of first and second operand, and result
	char *args[3] = {mx_strtrim(argv[1]),mx_strtrim(argv[3]),mx_strtrim(argv[4])};
	//depending on operation sign, call the func calc to calculate and print result
	switch (op){
		case '+':
			calc(args, '+');
			break;
		case '-':
			calc(args, '-');
			break;
		case '*':
			calc(args, '*');
			break;
		case '/':
			//avoid division by 0
			if(mx_strcmp(args[1], "0") == 0){
				mx_printerr("\n");
				exit(0);
			}
			else calc(args, '/');
			break;
		case '?':
			calc(args, '?');
			break;
	}
}

