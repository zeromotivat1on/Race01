#include "../inc/calculator.h"

void mx_str_reverse(char *str){
	if(!str) return;
	int len = mx_strlen(str);
	for(int i = 0; i < len / 2; ++i){
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

