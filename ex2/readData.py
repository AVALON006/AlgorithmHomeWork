import re

TEST_ITEM_NUM=9

def readData(filename):
    '''返回：背包容量C 物品数量n 最优解bv 花费的时间nt 物品重量w 物品价值v'''
    data=open(filename,encoding="utf-8")
    item_num=[];
    max_val=[];
    need_time=[];
    item_weight_arrs=[];
    item_val_arrs=[];
    knapsack_capacity=data.readline()
    line=data.readline()
    for i in range(TEST_ITEM_NUM):
        item_num.append(data.readline())
        max_val.append(data.readline())
        need_time.append(data.readline())
        item_weight_arrs.append(data.readline().split())
        item_val_arrs.append(data.readline().split())
        line=data.readline()
    
    C=int(knapsack_capacity.split("：")[1])
    n=[int(i.split("：")[1]) for i in item_num]
    bv=[int(i.split("：")[1]) for i in max_val]
    nt=[float(i.split("：")[1]) for i in need_time]
    w=[[int(re.findall(r"\-?\d+",i)[0]) for i in item] for item in item_weight_arrs]
    v=[[int(re.findall(r"\-?\d+",i)[0]) for i in item] for item in item_val_arrs]
    
    return C,n,bv,nt,w,v
