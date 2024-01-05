#! /usr/bin/python3
import os
import subprocess


directory = '/home/yanxiang/Desktop/MyProject/Cpp-Project/wasi-test/src'  # 替换为你要获取文件名的目录路径
change_dir = '/home/yanxiang/Desktop/MyProject/Cpp-Project/wasi-test/build/bin'

program_name = []


# 获取目录下所有文件
for filename in os.listdir(directory):
    if os.path.isfile(os.path.join(directory, filename)):
        file_name, file_extension = os.path.splitext(filename)
        program_name.append(file_name)
# 切换目录
os.chdir(change_dir)
# 清空result.txt
file_path = 'result.txt'  # 替换为你要清空内容的文件路径
# 使用 'w' 模式打开文件，立即清空文件内容
with open(file_path, 'w') as file:
    pass

for name in program_name:
    wasmedge_name = name + '.wasmedge'
    wamr_name = name + '.aot'
    wasmedge_command = ['wasmedge','--dir=./', wasmedge_name]
    wamr_command = ['iwasm', '--dir=./', wamr_name]
    native_command = ['./' + name]

    try:
        subprocess.run(native_command, check=True)
        subprocess.run(wamr_command, check=True)
        subprocess.run(wasmedge_command, check=True)
        # print(f"运行成功: {name}")
    except subprocess.CalledProcessError as e:
        print(f"运行失败: {name}")
        print(e)

