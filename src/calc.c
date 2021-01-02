#include "../inc/calculator.h"

void calc(char **args, int sign){
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
		//printf("q_index:%d\tlen[%d]:%d\n",q_index,i,len[i]);
		for(int j = 0; j < len[i] - 1 - q_index; ++j) {
			coff[i][index] = '0';
			index++;
		}
	}

	/*printf("0 size:%d\tq_size:%d\tcoff:%d\n",mx_atoi(size[0]),mx_atoi(q_size[0]), mx_atoi(coff[0]));
	printf("1 size:%d\tq_size:%d\tcoff:%d\n",mx_atoi(size[1]),mx_atoi(q_size[1]), mx_atoi(coff[1]));
	printf("2 size:%d\tq_size:%d\tcoff:%d\n",mx_atoi(size[2]),mx_atoi(q_size[2]), mx_atoi(coff[2]));*/

	for(int k = mx_atoi(size[0]); k <= mx_atoi(q_size[0]); k += mx_atoi(coff[0])){
		for(int l = mx_atoi(size[1]); l <= mx_atoi(q_size[1]); l += mx_atoi(coff[1])){
			for(int m = mx_atoi(size[2]); m <= mx_atoi(q_size[2]); m += mx_atoi(coff[2])){
				if(sign == '+'){
					if((k + l) == m){
						int sum = k + l;
						mx_printint(k);
						mx_printstr(" + ");
						mx_printint(l);
						mx_printstr(" = ");
						mx_printint(sum);
						mx_printchar('\n');
					}
				}
				if(sign == '-'){
					if((k - l) == m){
						int sub = k - l;
						mx_printint(k);
						mx_printstr(" - ");
						mx_printint(l);
						mx_printstr(" = ");
						mx_printint(sub);
						mx_printchar('\n');
					}
				}
				if(sign == '*'){
					if((k * l) == m){
						int mul = k * l;
						mx_printint(k);
						mx_printstr(" * ");
						mx_printint(l);
						mx_printstr(" = ");
						mx_printint(mul);
						mx_printchar('\n');
					}
				}
				if(sign == '/'){
					if((k / l) == m){
						int div = k / l;
						mx_printint(k);
						mx_printstr(" / ");
						mx_printint(l);
						mx_printstr(" = ");
						mx_printint(div);
						mx_printchar('\n');
					}
				}
			}
		}
	}
}

