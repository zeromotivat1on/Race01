#include "../inc/calculator.h"

void add(char **args){
	int len[3];
	char *size[3], *q_size[3];
	for(int i = 0; i < 3; ++i){
		len[i] = mx_strlen(args[i]);
		size[i] = mx_strnew(len[i]);
		q_size[i] = mx_strnew(len[i]);
		//mx_strcat(size[i], args[i]);
		for(int x = 0; x < len[i]; ++x){
			if(args[i][x] == '?'){
				size[i][x] = '0';
			}
			else mx_strcat(&size[i][x], &args[i][x]);
			mx_strcat(&q_size[i][x], "9");
		}
	}

	printf("0 size:%d\tq_size:%d\n",mx_atoi(size[0]), mx_atoi(q_size[0]));
	printf("1 size:%d\tq_size:%d\n",mx_atoi(size[1]),mx_atoi(q_size[1]));
	printf("2 size:%d\tq_size:%d\n",mx_atoi(size[2]),mx_atoi(q_size[2]));

	for(int k =  0; k <= mx_atoi(q_size[0]); ++k){
		for(int l = 0; l <= mx_atoi(q_size[1]); ++l){
			//for(int m = mx_atoi(size[2]); m <= mx_atoi(size[2]); ++m){
				if((k + l) == mx_atoi(size[2])
					&& k == mx_atoi(&args[k][l])){
					int sum = k + l;
					mx_printint(k);
					mx_printstr(" + ");
					mx_printint(l);
					mx_printstr(" = ");
					mx_printint(sum);
					mx_printchar('\n');
				}
			//}
		}
	}
}

