sr=input()

for i in range(0,len(sr)):
    if(sr[i]==' '):
        print(' ',end='',sep='')
    elif(sr[i]=="'" or sr[i]=='2'):
        pass
    else:
        print(sr[i],end='',sep='')
        
        if(sr[1+i]=="'"):
            print("(1);\t\t\t",end='',sep='')
        elif (sr[i+1]=='2'):
            print("(1); ",sr[i],"(1);","\t\t\t",end='',sep='')
        else:
            print("(0);\t\t\t",end='',sep='')

print("\n")
for i in range(0,len(sr)):
    if(sr[i]==' '):
        print(' ',end='',sep='')
    elif(sr[i]=="'" or sr[i]=='2'):
        pass
    else:
        print("push('",sr[i],"',",end='',sep='')
        
        
        if(sr[1+i]=="'"):
            print("1);\t",end='',sep='')
        elif (sr[i+1]=='2'):
            print("2);\t",end='',sep='')
        elif(sr[i+1]==' '):
            print("0);\t",end='',sep='')
        else:
            print("(0);\t\t\t",end='',sep='')