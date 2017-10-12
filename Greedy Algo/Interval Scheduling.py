#Interval Scheduling
#A,starting time, ending time
#results name of process such that there are maximum process in the interval



proc = [('A',1,6),('B',5,13),('C',7,12)]
proc = sorted(proc,key=lambda x:x[2]) #key=tells sort by whicg element
todo=[]

def check(i):
    if(proc[i][1]<proc[i-1][2]):
        return False
    else:
        return True

def greedy():
    todo.append(proc[0][0])
    for i in range(1,len(proc)):
        if(check(i)==True):
            todo.append(proc[i][0])
        else:
            pass
greedy()
print(todo)

        
        
