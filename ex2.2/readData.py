import re

TEST_NUM=7

def readData(filename):
    '''返回：fn（第一个表示n，第二个表示f(n)） 分治法加法次数divt 动态规划法加法次数dynt'''
    data=open(filename,encoding="utf-8")
    fn=[];
    divide_times=[];
    dynamic_times=[];
    for i in range(TEST_NUM):
        fn.append(data.readline())
        divide_times.append(data.readline())
        dynamic_times.append(data.readline())
        line=data.readline()
    fn=[[int(i) for i in re.findall("\d+",f)] for f in fn];
    divt=[int(re.findall("\d+",dt)[0]) for dt in divide_times];
    dynt=[int(re.findall("\d+",dt)[0]) for dt in dynamic_times];
    
    return fn,divt,dynt

