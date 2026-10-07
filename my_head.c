#include <stdio.h>
#include <stdlib.h>     /* atoi(新!) */
#include <string.h>     /* strcmp(新!) */
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int n_lines = 10;
	char *filename = NULL;

	/* ① 遍历解析(上面讲过) */
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
			n_lines = atoi(argv[i + 1]);
			i++;
		} else { 
			filename = argv[i];
		}
	}
	if (filename == NULL) {
		fprintf(stderr, "用法 %s [-n 行数] <文件名>\n",argv[0]);
		return 1;
	}

	int fd = open(filename, O_RDONLY);
	if (fd < 0) { perror("open"); return 1; }

	/* ② 骨架B拼行 + ③提前退出(两骨架合体就在这一行) */
	char line[1024];
	char c;
	int line_len = 0,line_count = 0;

	while (read(fd, &c, 1) == 1 && line_count < n_lines) {
		if (c == '\n') {
			line[line_len] = '\0';
			printf("%s\n",line);
			line_count++;
			line_len = 0;
		} else if (line_len < (int)sizeof(line) - 1) {
			line[line_len++] = c;
		}
	}
	close(fd);
	return 0;
}
