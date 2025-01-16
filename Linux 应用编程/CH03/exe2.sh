#!/usr/bin/env zsh
# 脚本说明：使用Oh-My-Zsh，实现多个数字相加求和，并保留两位小数。
# Made By 10235101526 张梓卫

# 定义函数检查输入是否为数字
isNumber() {
  if [[ $1 =~ ^-?[0-9]+(\.[0-9]+)?$ ]]; then # 使用正则表达式判断是否为数字
    return 0
  else
    return 1
  fi
}

total=0

echo "Please input numbers (input 'end' to stop):"

while true; do
  read input
  if [ "$input" == "end" ]; then
    break
  fi

  if isNumber "$input"; then
    total=$(echo "$total + $input" | bc)
  else
    echo "Error:'$input' is not a valid number。"
  fi
done

# 保留两位小数
printf "The sum is: %.2f\n" "$total"
