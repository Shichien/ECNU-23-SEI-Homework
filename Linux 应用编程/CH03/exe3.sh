#!/usr/bin/env zsh
# 脚本说明：使用 Oh-My-Zsh 终端，将dir2中符合下列条件的文件复制到dir1，并将每一条复制记录存储到文件record中。
# Made By 10235101526 张梓卫

dir1=$1
dir2=$2
record="record"

if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]; then
  echo "Error: dir1 or dir2 is not a directory."
  exit 1
fi

for file in "$dir2"/*; do
  filename=$(basename "$file")
  file_in_dir1="$dir1/$filename"

  if [ ! -e "$file_in_dir1" ] || [ "$file" -nt "$file_in_dir1" ]; then
    cp "$file" "$dir1/"
    echo "Copy $filename to $dir1" >> "$record"
  fi
done
