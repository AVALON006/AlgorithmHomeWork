TEST_ITEM_NUM=10

def readData(filename):
    '''返回：背包容量C 物品数量n 花费的时间nt'''
    data=open(filename,encoding="utf-8")
    item_num=[];
    need_time=[];
    knapsack_capacity=data.readline()
    line=data.readline()
    for i in range(TEST_ITEM_NUM):
        item_num.append(data.readline())
        need_time.append(data.readline())
        nothing=data.readline()
        nothing=data.readline()
        nothing=data.readline()
        nothing=data.readline()
        line=data.readline()
    C=int(knapsack_capacity.split("：")[1])
    n=[int(i.split("：")[1]) for i in item_num]
    nt=[float(i.split("：")[1]) for i in need_time]
    
    return C,n,nt