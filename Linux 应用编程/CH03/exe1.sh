#!/usr/bin/env zsh
# 脚本说明：使用Oh-My-Zsh的命令行工具，实现文件或目录的压缩、解压缩、归档压缩等操作。
# Made By 10235101526 张梓卫

par=$1

if [ ! -e "$par" ]; then # 若文件不存在 [-e 是检查指令]
    echo "Error：File or directory '$par' not found."
    exit 1
fi

if [ -f "$par" ]; then #
  cat "$par"

elif [[ "$par" == *.tar.gz ]]; then # 如果参数是压缩文件（以.tar.gz结尾）
  filename="${par%.tar.gz}"
  if [ -e "$filename" ]; then
    echo "The file with the same name already exists."
  else
    tar -xzvf "$par"
  fi

elif [ -d "$par" ]; then # 如果参数是目录
  archive="${par}.tar.gz"
  if [ -e "$archive" ]; then
    echo "The file with the same name already exists."
  else
    tar -czvf "$archive" "$par"
  fi

else
  echo "Unknown file or directory."
fi
