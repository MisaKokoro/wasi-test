#!/bin/bash

directory="/home/yanxiang/Desktop/MyProject/Cpp-Project/wasi-test/src"
change_dir="/home/yanxiang/Desktop/MyProject/Cpp-Project/wasi-test/build/bin"
program_names=()

# 获取目录下所有文件
for filename in "$directory"/*; do
    if [ -f "$filename" ]; then
        name=$(basename -- "$filename")
        file_name="${name%.*}"
        program_names+=("$file_name")
    fi
done

# 切换目录
cd "$change_dir" || exit

# 清空result.txt
file_path="result.txt"
> "$file_path"

for name in "${program_names[@]}"; do
    wasmedge_name="$name.wasmedge"
    wamr_name="$name.aot"
    wasmedge_command=("wasmedge" "--dir=./" "$wasmedge_name")
    wamr_command=("iwasm" "--dir=./" "$wamr_name")
    native_command=("./$name")

    if ! "${native_command[@]}"; then
        echo "运行失败: $name"
        continue
    fi
    
    if ! "${wamr_command[@]}"; then
        echo "运行失败: $name"
        continue
    fi



    if ! "${wasmedge_command[@]}"; then
        echo "运行失败: $name"
        continue
    fi
done
