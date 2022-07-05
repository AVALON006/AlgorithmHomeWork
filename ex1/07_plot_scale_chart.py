import pandas as pd
from readData import readData
from pylab import mpl
import os
import matplotlib.pyplot as plt

mpl.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体

if os.getcwd().find("ex1")==-1:
    data1=readData(".\\ex1\\data1.txt")
else:
    data1=readData("data1.txt")

msscale=data1[9];qsscale=data1[10];
name=data1[3];

msscale.sort()
qsscale.sort()

msscale=list(set(msscale))
qsscale=list(set(qsscale))

lenmsscale=len(msscale);
lenqsscale=len(qsscale);

if (lenmsscale>lenqsscale):
    for i in range(lenmsscale-lenqsscale):
        qsscale.append('')
else:
    for i in range(lenqsscale-lenmsscale):
        msscale.append('');

dict = {
    name[1]: msscale,
    name[2]: qsscale,
}

colors=["fuchsia"]*2
cell_colors=[[".95" for c in range(2)] for r in range(max(lenmsscale,lenqsscale))]

cellText=[];
for i in range(max(lenmsscale,lenqsscale)):
    cellText.append([msscale[i],qsscale[i]])

tab =plt.table(
    cellText=cellText,
    colLabels=name[1:3],  # type: ignore
    colLoc='center',
    colColours=colors,  # type: ignore
    cellColours=cell_colors,
    rowLoc='center',loc='center')
tab.set_fontsize(12)
tab.scale(1,2)
tab.auto_set_column_width(range(len(name)))
plt.axis('off')
plt.subplots_adjust(left=0,bottom=0.25,right=1,top=0.75,wspace=0,hspace=0)
plt.savefig(".\\img\\子问题规模表.png")
plt.show()
