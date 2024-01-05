#!/usr/bin/python3
import os
import subprocess

# 目录路径
directory = '/home/yanxiang/Desktop/MyProject/Cpp-Project/wasi-test/build/bin/'

# 获取目录下所有以 .c 结尾的文件
wasm_files = [file for file in os.listdir(directory) if file.endswith('.wasm')]

# 遍历每个 .c 文件并使用 gcc 进行编译
for wasm_file in wasm_files:
    # 构建文件路径
    file_path = os.path.join(directory, wasm_file)
    
    # 构建编译命令
    wasmedge_command = ['wasmedge','compile', file_path, directory + os.path.splitext(wasm_file)[0] + '.wasmedge']
    wamr_command = ['wamrc', '-o', directory + os.path.splitext(wasm_file)[0] + '.aot', file_path]
    
    # 执行编译命令
    try:
        subprocess.run(wamr_command, check=True)
        subprocess.run(wasmedge_command, check=True)
        print(f"编译成功: {wasm_file}")
    except subprocess.CalledProcessError as e:
        print(f"编译失败: {wasm_file}")
        print(e)