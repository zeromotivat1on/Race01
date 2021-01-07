#pragma once 
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void mx_printerr(const char *str);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_strdel(char **str);
char *mx_strndup(const char *str, size_t n);
char *mx_del_extra_spaces(const char *str);
int mx_atoi(const char *str);
void mx_printstr(const char *s);
char *mx_strcat(char *restrict s1, const char *restrict s2);
void mx_printint(int n);
void mx_printchar(char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char* src);
char *mx_strdup(const char *str);
char *mx_itoa(int number);
void mx_str_reverse(char *str);

void calc(char **args, char sign);

#endif

