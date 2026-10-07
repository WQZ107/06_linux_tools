#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {                                   /* 参数检查 */
        fprintf(stderr, "用法: %s <源文件> <目标文件>\n", argv[0]);
        return 1;
    }
    int src = open(argv[1], O_RDONLY);
    if (src < 0) { perror("打开文件失败"); return 1; }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) { perror("创建目标文件失败"); close(src); return 1; }

    char buf[4096];
    int len;
    while ((len = read(src, buf, sizeof(buf))) > 0) {   /* 读到EOF为止 */
        write(dst, buf, len);                          /* 写入目标文件	*/
    }
    close(src);
    close(dst);
    return 0;
}
