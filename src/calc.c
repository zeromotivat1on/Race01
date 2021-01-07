#include "../inc/calculator.h"

void calc(char **args, char sign){
	int len[3];
	char *size[3], *q_size[3], *coff[3];
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

	/*printf("0 size:%d\tq_size:%d\tcoff:%d\n",mx_atoi(size[0]),mx_atoi(q_size[0]), mx_atoi(coff[0]));
	printf("1 size:%d\tq_size:%d\tcoff:%d\n",mx_atoi(size[1]),mx_atoi(q_size[1]), mx_atoi(coff[1]));
	printf("2 size:%d\tq_size:%d\tcoff:%d\n",mx_atoi(size[2]),mx_atoi(q_size[2]), mx_atoi(coff[2]));*/

	char **strs_res = (char **)malloc(100 * (mx_atoi(q_size[0]) + mx_atoi(q_size[1])) * sizeof(char *));
	int str_amnt = 0;

	for(int k = mx_atoi(size[0]); k <= mx_atoi(q_size[0]); k += mx_atoi(coff[0])){
		for(int l = mx_atoi(size[1]); l <= mx_atoi(q_size[1]); l += mx_atoi(coff[1])){
			for(int m = mx_atoi(size[2]); m <= mx_atoi(q_size[2]); m += mx_atoi(coff[2])){
				if(sign == '+' || sign == '?'){
					if((k + l) == m){
						int sum = k + l;
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " + ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(sum));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
						
					}
				}
				if(sign == '-' || sign == '?'){
					if((k - l) == m){
						int sub = k - l;
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " - ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(sub));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
					}
				}
				if(sign == '*' || sign == '?'){
					if((k * l) == m){
						int mul = k * l;
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " * ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(mul));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
					}
				}
				if(sign == '/'  || sign == '?'){
					if(l != 0 && (k / l) == m){
						int div = k / l;
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(k));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " / ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(l));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], " = ");
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], mx_itoa(div));
						strs_res[str_amnt] = mx_strjoin(strs_res[str_amnt], "\n");
						str_amnt++;
					}
				}
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '+'){
				printf("%s", strs_res[i]);
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '-'){
				printf("%s", strs_res[i]);
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '*'){
				printf("%s", strs_res[i]);
			}
		}
	}
	for(int i = 0; i < str_amnt; ++i){
		for(int j = 0; j < mx_strlen(strs_res[i]); ++j){
			if(strs_res[i][j] == '/'){
				printf("%s", strs_res[i]);
			}
		}
	}
}

