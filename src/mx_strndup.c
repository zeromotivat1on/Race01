#include "../inc/calculator.h"

char *mx_strndup(const char *str, size_t n){
	size_t size = mx_strlen(str);
	if(n < size) size = n;
	char *res = mx_strnew(size);
	if(res == NULL) return NULL;
	return (mx_strncpy(res, str, size));
}

