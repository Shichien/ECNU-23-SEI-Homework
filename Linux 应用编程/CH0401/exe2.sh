#!/bin/bash

# 请注意使用 chmod +x ./exe2.sh 命令为脚本添加可执行权限
pattern1='^[a-z].*[0-9]$'       # 小写字母开头，以数字结尾
pattern2='[0-9]+[a-zA-Z]+'      # 一个或多个数字，后跟一个或多个字母

# 检查是否提供参数
if [ -z "$1" ]; then
    echo "Usage: $0 <input-file>"
    exit 1
fi

grep -E "$pattern1" "$1" > record2

# 符合第二个模式的行，追加到 record2 文件的后面
grep -E "$pattern2" "$1" >> record2

~