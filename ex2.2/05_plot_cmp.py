from readData import readData
from pylab import mpl
import matplotlib.pyplot as plt
import os

mpl.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体

if(os.getcwd().find("ex")==-1):
    res=readData(".\\ex2.2\\result.txt")
else:
    res=readData("result.txt")
# 返回：fn（第一个表示n，第二个表示f(n)） 分治法加法次数divt 动态规划法加法次数dynt

n=[];
for i in res[0]:
    n.append(i[0])

plt.figure("比较图")
plt.title("加法次数对比图")
plt.plot(n,res[1],'ro-')
plt.plot(n,res[2],'bo-')
plt.xlabel("问题规模n（第n个斐波那契数）")
plt.ylabel("加法比较次数")
plt.legend(["分治法","动态规划法"])
plt.savefig(".\\img\\加法次数对比图.png")
plt.show()