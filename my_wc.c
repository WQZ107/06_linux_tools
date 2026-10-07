#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "用法：%s <文件名>\n",argv[0]);
		return 1;
	}
	int fd = open(argv[1],O_RDONLY);
	if (fd < 0) { perror("open"); return 1; }

	int lines = 0, words = 0, chars = 0;
	int in_word = 0;
	char c;

	while (read(fd, &c, 1) == 1) {
		chars++;
		if (c == '\n') lines++;
		if (c == ' ' || c == '\n' || c == '\t') {
			in_word = 0;
		} else if (in_word == 0) {
			in_word = 1;
			words++;
		}
	}
	printf("%d行 %d个单词 %d个字符 %s\n",lines,words,chars,argv[1]);
	close(fd);
	return 0;
}
