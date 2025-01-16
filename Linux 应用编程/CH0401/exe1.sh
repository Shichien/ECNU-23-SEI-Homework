#!/bin/bash

# 请注意使用 chmod +x ./exe1.sh 命令为脚本添加可执行权限
cp /etc/passwd step1.txt
tr -s '[:space:][:punct:]' '\n' < step1.txt > step2.txt
sort step2.txt > step3.txt
uniq -c step3.txt > step4.txt
sort -nr step4.txt > record1
rm step1.txt step2.txt step3.txt step4.txt