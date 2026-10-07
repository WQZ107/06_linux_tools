# 06_linux_tools
61-70天阶段成果:五个 Linux 命令行工具的 C 语言原理版(逐字符读/文件IO/参数解析)

| 工具 | 功能 | 用法 |
|---|---|---|
| my_cat | 打印文件内容 | ./my_cat <文件名> |
| my_cp | 复制文件(手撕文件复制) | ./my_cp <源> <目标> |
| my_wc | 统计行/单词/字节 | ./my_wc <文件名> |
| my_grep | 按关键字筛选行 | ./my_grep <关键字> <文件名> |
| my_head | 取前N行(默认10,支持-n) | ./my_head [-n 行数] <文件名> |

技术点:open/read/write/close 系统调用、文件描述符、argc/argv 解析、
in_word 状态机、拼行缓冲、strstr、防御式错误处理(stderr+perror)。
