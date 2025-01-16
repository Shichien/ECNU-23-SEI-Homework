#bin/bash

# 首行显示列表标题
echo "List of Users" > awk1.out
# 标题后输出分割线
echo "--------------------------------" >> awk1.out

# 显示用户名、组名、Shell 路径，UserName, GroupName, Shell Path
# 要做到按列对齐

echo -e "UserName\t\tGroupName\t\tShell Path" >> awk1.out
echo "--------------------------------" >> awk1.out

# 使用 awk 命令，将 /etc/passwd 文件中的用户名、组名、Shell 路径提取出来
awk -F: '{
  split($7, shell, "/");
  if (shell[1] == "") shell[1] = "root";
  printf "%-20s %-20s %-20s\n", $1, shell[1], $7;
}' /etc/passwd >> awk1.out

echo "--------------------------------" >> awk1.out

echo "Shell Path Statistics:" >> awk1.out

awk -F: '{
    shell_count[$7]++;
}
END {
    for (shell in shell_count) {
        printf "%-30s %d\n", shell, shell_count[shell];
    }
}' /etc/passwd >> awk1.out

# 提示输出完成
echo "Output written to awk1.out"