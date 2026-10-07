#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "用法: %s <文件名>\n", argv[0]);
		return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {perror("打开文件夹失败"); return 1; }

	char buf[1024];
	int len;
	while ((len = read(fd, buf, sizeof(buf))) > 0) {	//读到EOF为止
		write(1, buf, len);				//1 = 标准输出
	}
	close(fd);
	return 0;
}
