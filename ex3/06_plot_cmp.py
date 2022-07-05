from readData import readData
from pylab import mpl
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import os

mpl.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体

if(os.getcwd().find("ex")==-1):
    res=readData(".\\ex2.2\\result.txt")
else:
    res=readData("result.txt")
# 返回：背包容量C 物品数量n 花费的时间nt

plt.figure("时间趋势图")
plt.title("时间趋势图")
plt.plot(res[1],res[2],'ro-')
plt.xlabel("物品数量")
plt.ylabel("求解花费的时间")
plt.gca().yaxis.set_major_formatter(mticker.FormatStrFormatter('%.3fms'))
plt.gca().xaxis.set_major_formatter(mticker.FormatStrFormatter('%d个'))
plt.savefig(".\\img\\时间趋势图.png")
plt.show()

plt.figure(1)
plt.title("时间趋势图")
plt.plot(res[1][0:-4],res[2][0:-4],'ro-')
plt.xlabel("物品数量")
plt.ylabel("求解花费的时间")
plt.gca().yaxis.set_major_formatter(mticker.FormatStrFormatter('%.3fms'))
plt.gca().xaxis.set_major_formatter(mticker.FormatStrFormatter('%d个'))
plt.savefig(".\\img\\前几个的图.png")