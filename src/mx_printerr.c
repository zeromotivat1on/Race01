#include "../inc/calculator.h"

void mx_printerr(const char *str){
	write(2, str, mx_strlen(str));
}

