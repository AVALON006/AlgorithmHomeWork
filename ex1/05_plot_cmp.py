from readData import readData
from pylab import mpl
import matplotlib.pyplot as plt
import os

mpl.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体

if os.getcwd().find("ex1")==-1:
    data1=readData(".\\ex1\\data1.txt")
    data2=readData(".\\ex1\\data2.txt")
else:
    data1=readData("data1.txt")
    data2=readData("data2.txt")

col=list("第"+str(i+1)+"次测试" for i in range(2))
col.insert(0,"算法名称")
vals=[[data1[6],data2[6]],[data1[7],data2[7]],[data1[8],data2[8]]]
vals=list(list(map(str,val)) for val in vals)
plt.figure(figsize=(4,len(col)),dpi=80)
colors=["lightskyblue"]+["fuchsia"]*2
cell_colors=[[".95" for c in range(3)] for r in range(3)]
for i in range(3):
    vals[i].insert(0,data1[3][i])
    cell_colors[i][0]="lawngreen"
tab =plt.table(
    cellText=vals,
    colLabels=col,  # type: ignore
    colLoc='center',
    colColours=colors,  # type: ignore
    cellColours=cell_colors,
    rowLoc='center',loc='center')
tab.set_fontsize(12)
tab.scale(1,2)
tab.auto_set_column_width(range(len(col)))
plt.axis('off')
plt.subplots_adjust(left=0,bottom=0,right=1,top=1,wspace=0.1,hspace=0.1)
plt.savefig(".\\img\\cmp.png",bbox_inches='tight',pad_inches=-0.5)
