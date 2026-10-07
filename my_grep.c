#include<stdio.h>
#include <string.h>                          /* strstr 的头文件(新!) */
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
	if (argc != 3) {			//关键字+文件名=程序名+2,共3个
		fprintf(stderr,"用法: %s <关键字> <文件名>\n",argv[0]);
		return 1;
	}

	int fd = open(argv[2], O_RDONLY);		//注意：是argv[2] 不是argv[1]
	if (fd < 0) { perror("open"); return 1; }	//关键字占了 argv[1],文件名被挤到后一位
	
	char line[1024];
	char c;
	int line_len = 0,line_no = 0;
	
	while (read(fd, &c ,1) == 1) {
		if (c == '\n') {		//一行结束
			line[line_len] = '\0';	/* 补结束符(坑4:漏了=残影) */
			line_no++;
			if (strstr(line, argv[1]) != NULL) {	/* 大串在前,小串在后 */
				printf("%d: %s\n",line_no , line);
			}
			line_len = 0;				/* 清碗 */
		} else if (line_len < (int)sizeof(line) - 1) {
			line[line_len++] = c;			/* 防越界:最多攒1023个,超长行的尾巴丢弃 */

		}
	}
	if (line_len > 0) {
		line[line_len] = '\0';
		if (strstr(line, argv[1]) != NULL)
			printf("%d: %s\n", ++line_no, line);
	}
	close(fd);
	return 0;
}
