from readData import readData
from pylab import mpl
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import os

mpl.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体
if(os.getcwd().find("ex")==-1):
    data1=readData(".\\ex2\\data1.txt")
    data2=readData(".\\ex2\\data2.txt")
    data3=readData(".\\ex2\\data3.txt")
    data4=readData(".\\ex2\\data4.txt")
    data5=readData(".\\ex2\\data5.txt")
else:
    data1=readData("data1.txt")
    data2=readData("data2.txt")
    data3=readData("data3.txt")
    data4=readData("data4.txt")
    data5=readData("data5.txt")
# 返回：背包容量C 物品数量n 最优解bv 花费的时间nt 物品重量w 物品价值v
# C=[];n=[];bv=[];nt=[];w=[];v=[]
# C.append(data1[0]);n.append(data1[1]);bv.append(data1[2]);nt.append(data1[3]);w.append(data1[4]);v.append(data1[5]);
# C.append(data2[0]);n.append(data2[1]);bv.append(data2[2]);nt.append(data2[3]);w.append(data2[4]);v.append(data2[5]);
# C.append(data3[0]);n.append(data3[1]);bv.append(data3[2]);nt.append(data3[3]);w.append(data3[4]);v.append(data3[5]);
# C.append(data4[0]);n.append(data4[1]);bv.append(data4[2]);nt.append(data4[3]);w.append(data4[4]);v.append(data4[5]);
# C.append(data5[0]);n.append(data5[1]);bv.append(data5[2]);nt.append(data5[3]);w.append(data5[4]);v.append(data5[5]);
C=[];n=[];bv=[];nt=[]
C.append(data1[0]);n.append(data1[1]);bv.append(data1[2]);nt.append(data1[3]);
C.append(data2[0]);n.append(data2[1]);bv.append(data2[2]);nt.append(data2[3]);
C.append(data3[0]);n.append(data3[1]);bv.append(data3[2]);nt.append(data3[3]);
C.append(data4[0]);n.append(data4[1]);bv.append(data4[2]);nt.append(data4[3]);
C.append(data5[0]);n.append(data5[1]);bv.append(data5[2]);nt.append(data5[3]);

linetype=['ro-','bo-','go-','ko-','yo-']

for i in range(5):
    name="背包容量="+str(C[i])
    plt.figure(name)
    plt.plot(n[i],nt[i],linetype[i])
    plt.title(name)
    plt.xlabel("物品数量")
    plt.ylabel("程序执行时间")
    plt.gca().yaxis.set_major_formatter(mticker.FormatStrFormatter('%.3fms'))
    plt.gca().xaxis.set_major_formatter(mticker.FormatStrFormatter('%d个'))
    plt.savefig(".\\img\\"+name+".png")

plt.figure("综合版")
plt.title("综合版")
plt.xlabel("物品数量")
plt.ylabel("程序执行时间")
for i in range(5):
    name="背包容量="+str(C[i])
    plt.plot(n[i],nt[i],linetype[i])

plt.legend(["问题规模："+str(num) for num in C])
plt.gca().yaxis.set_major_formatter(mticker.FormatStrFormatter('%.3fms'))
plt.gca().xaxis.set_major_formatter(mticker.FormatStrFormatter('%d个'))
plt.savefig(".\\img\\综合版.png")
print("print");