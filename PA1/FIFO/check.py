import os
import random
from time import time


def checkAns(outputFile1, outputFile2):
    """
        该函数用于判断两个输入文件是否相同，这里采用的方式是读入两个文件的所有行，然后拼起来判断是否相同。可以根据需求修改
        outputFile1,outputFile2 分别为判断的两个文件的文件名
        函数返回布尔值
    """
    with open(outputFile1, "r") as f:
        output1 = f.readlines()
    with open(outputFile2, "r") as f:
        output2 = f.readlines()
    return "".join(output1) == "".join(output2)


def dataMaker(inputFile, n, m, valuelength):
    """
        这个函数根据自己的需求一定要修改，他负责根据读入的参数来生成一个测试文件inputFile。
        在A+B问题里面,n用来控制生成的数组组数，valuelength用来控制用于乘法的长度。
    """
    with open(inputFile, "w") as f:
        N = str(random.randint(1, n))
        length = random.randint(1, m)
        M = str(length)
        f.write(N+" "+M+"\n")
        for i in range(0,length):
            S3 = str(random.randint(1, valuelength))
            f.write(S3 + " ")
if __name__ == '__main__':
    while True:
        # 每组数据?个，长度为?
        dataMaker("input.txt", 100000, 10000, 10000)

        # 运行a读入input.txt输出到output1.txt,a.cpp是c++代码需要编译之后得到可执行程序a
        #os.system("./homework < input.txt >output1.txt")
        start = time()
        os.system("./baoli < input.txt >output1.txt")
        stop = time()
        print(str(stop-start) + "秒")
        # 运行b读入input.txt输出到output1.txt,b.py是python代码通过python指令运行
        start = time()
        os.system("./fix < input.txt >output2.txt")
        stop = time()
        print(str(stop-start) + "秒")

        if checkAns("output1.txt", "output2.txt") is False:
            print("Wrong")
            break
        print("right")
