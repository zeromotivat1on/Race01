#include "../inc/calculator.h"

void calc(char **args, char sign){

	/*
	 * len - array of args length
	 * size - array of starting points for loop for each argument
	 * q_size - array of ending points for loop for each argument
	 * coff - array of numbers that we add to size for each argument
	 */

	int len[3];
	char *size[3], *q_size[3], *coff[3];
	//setting starting and ending points, coff as well
	for(int i = 0; i < 3; ++i){
		len[i] = mx_strlen(args[i]);
		size[i] = mx_strnew(len[i]);
		q_size[i] = mx_strnew(len[i]);
		coff[i] = mx_strnew(len[i]);
		for(int x = 0; x < len[i]; ++x){
			if(args[i][x] == '?'){
				size[i][x] = '0';
				q_size[i][x] = '9';
			}
			else {
				size[i][x] = args[i][x];
				q_size[i][x] = args[i][x];
			}
		}
		int index = 0, q_index = 0;
		coff[i][index] = '1';
		index++;
		for(int x = 0; x < len[i]; ++x){
			if(args[i][x] == '?'){
				q_index = x;
			}
		}
		for(int j = 0; j < len[i] - 1 - q_index; ++j) {
			coff[i][index] = '0';
			index++;
		}
	}
	
	int res_size = 0;
	if(mx_atoi(q_size[0]) < 1000 || mx_atoi(q_size[1]) < 1000){
		if(mx_atoi(q_size[0]) > mx_atoi(q_size[1])) res_size = mx_atoi(q_size[0]);
		else res_size = mx_atoi(q_size[1]);
	}
	else res_size = 1000;
	//array of result strings (e.g str = "1 + 1 = 2\n")
	char **strs_res = (char **)malloc(36 * res_size * sizeof(char *));
	int str_amnt = 0; //amount of total result strings
	for(int k = mx_atoi(size[0]); k <= mx_atoi(q_size[0]); k += mx_atoi(coff[1])){
		if(k > __INT_MAX__) exit(0);
		for(int l = mx_atoi(size[1]); l <= mx_atoi(q_size[1]); l += mx_atoi(coff[1])){
			if(l > __INT_MAX__) exit(0);
			for(int m = mx_atoi(size[2]); m <= mx_atoi(q_size[2]); m += mx_atoi(coff[2])){
			if(m > __INT_MAX__) exit(0);
				if((sign == '+' || sign == '?') && ((len[0] <= len[2]) && (len[1] <= len[2]))){
					if((k + l) > __INT_MAX__) exit(0);
					else if((k + l) == m){
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " + ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(m));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
						if(sign != '?') break;
					}
				}
				if(sign == '-' || sign == '?'){
					if((k - l) == m){
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " - ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(m));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
						if(sign != '?') break;
					}
				}
				if((sign == '*' || sign == '?') && ((len[0] <= len[2]) && (len[1] <= len[2]))){
					if((k * l) > __INT_MAX__) exit(0);
					else if((k * l) == m){
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " * ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(m));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
						if(sign != '?') break;
					}
				}
				if(sign == '/' || sign == '?'){
					//avoid division by 0
					if(l != 0 && (k / l) == m){
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " / ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(m));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
						if(sign != '?') break;
					}
				}
			}
		}
	}
	//'sort' result strings in such order: + - * /
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '+'){
				mx_printstr(strs_res[i]);
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '-'){
				mx_printstr(strs_res[i]);
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '*'){
				mx_printstr(strs_res[i]);
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '/'){
				mx_printstr(strs_res[i]);
			}
		}
	}
}

