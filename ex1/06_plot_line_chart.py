from readData import readData
from pylab import mpl
import matplotlib.pyplot as plt
import os

mpl.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体

if(os.getcwd().find("ex1")==-1):
    data3=readData(".\\ex1\\data3.txt")
    data4=readData(".\\ex1\\data4.txt")
    data5=readData(".\\ex1\\data5.txt")
    data6=readData(".\\ex1\\data6.txt")
    data7=readData(".\\ex1\\data7.txt")
    data8=readData(".\\ex1\\data8.txt")
    data9=readData(".\\ex1\\data9.txt")
    data10=readData(".\\ex1\\data10.txt")
    data11=readData(".\\ex1\\data11.txt")
    data12=readData(".\\ex1\\data12.txt")
    data13=readData(".\\ex1\\data13.txt")
else:
    data3=readData("data3.txt")
    data4=readData("data4.txt")
    data5=readData("data5.txt")
    data6=readData("data6.txt")
    data7=readData("data7.txt")
    data8=readData("data8.txt")
    data9=readData("data9.txt")
    data10=readData("data10.txt")
    data11=readData("data11.txt")
    data12=readData("data12.txt")
    data13=readData("data13.txt")
    
# n,floor,ceil,name,adata,sadata,bstimes,mstimes,qstimes,msscale,qsscale
scale=[];bstimes=[];mstimes=[];qstimes=[]
scale.append(data3[0]);bstimes.append(data3[6]);mstimes.append(data3[7]);qstimes.append(data3[8])
scale.append(data4[0]);bstimes.append(data4[6]);mstimes.append(data4[7]);qstimes.append(data4[8])
scale.append(data5[0]);bstimes.append(data5[6]);mstimes.append(data5[7]);qstimes.append(data5[8])
scale.append(data6[0]);bstimes.append(data6[6]);mstimes.append(data6[7]);qstimes.append(data6[8])
scale.append(data7[0]);bstimes.append(data7[6]);mstimes.append(data7[7]);qstimes.append(data7[8])
scale.append(data8[0]);bstimes.append(data8[6]);mstimes.append(data8[7]);qstimes.append(data8[8])
scale.append(data9[0]);bstimes.append(data9[6]);mstimes.append(data9[7]);qstimes.append(data9[8])
scale.append(data10[0]);bstimes.append(data10[6]);mstimes.append(data10[7]);qstimes.append(data10[8])
scale.append(data11[0]);bstimes.append(data11[6]);mstimes.append(data11[7]);qstimes.append(data11[8])
scale.append(data12[0]);bstimes.append(data12[6]);mstimes.append(data12[7]);qstimes.append(data12[8])
scale.append(data13[0]);bstimes.append(data13[6]);mstimes.append(data13[7]);qstimes.append(data13[8])
name=data3[3]

mscale=[]
ms1=[];ms2=[];ms3=[];ms4=[];ms5=[];ms6=[];ms7=[];ms8=[];ms9=[];ms10=[];ms11=[]
lastS=scale[0]
for s in data3[9]:
    if lastS<s:
        break
    ms1.append(s)
    lastS=s
lastS=scale[1]
for s in data4[9]:
    if lastS<s:
        break
    ms2.append(s)
    lastS=s
lastS=scale[2]
for s in data5[9]:
    if lastS<s:
        break
    ms3.append(s)
    lastS=s
lastS=scale[3]
for s in data6[9]:
    if lastS<s:
        break
    ms4.append(s)
    lastS=s
lastS=scale[4]
for s in data7[9]:
    if lastS<s:
        break
    ms5.append(s)
    lastS=s
lastS=scale[5]
for s in data8[9]:
    if lastS<s:
        break
    ms6.append(s)
    lastS=s
lastS=scale[6]
for s in data9[9]:
    if lastS<s:
        break
    ms7.append(s)
    lastS=s
lastS=scale[7]
for s in data10[9]:
    if lastS<s:
        break
    ms8.append(s)
    lastS=s
lastS=scale[8]
for s in data11[9]:
    if lastS<s:
        break
    ms9.append(s)
    lastS=s
lastS=scale[9]
for s in data12[9]:
    if lastS<s:
        break
    ms10.append(s)
    lastS=s
lastS=scale[10]
for s in data13[9]:
    if lastS<s:
        break
    ms11.append(s)
    lastS=s

plt.figure(name[0])
plt.plot(scale,bstimes,'ro-',label=name[0])
plt.title(name[0])
plt.xlabel("问题规模")
plt.ylabel("比较次数")
plt.savefig(".\\img\\"+name[0]+".png")
plt.figure(name[1])
plt.plot(scale,mstimes,'ro-',label=name[1])
plt.title(name[1])
plt.xlabel("问题规模")
plt.ylabel("比较次数")
plt.savefig(".\\img\\"+name[1]+".png")
plt.figure(name[2])
plt.plot(scale,qstimes,'ro-',label=name[2])
plt.title(name[2])
plt.xlabel("问题规模")
plt.ylabel("比较次数")
plt.savefig(".\\img\\"+name[2]+".png")

plt.figure("三者比较")
plt.plot(scale,bstimes,'ro-',scale,mstimes,'bo-',scale,qstimes,'go-')
plt.title("三者比较")
plt.legend(name)
plt.xlabel("问题规模")
plt.ylabel("比较次数")
plt.savefig(".\\img\\"+"三者比较.png")

plt.show()