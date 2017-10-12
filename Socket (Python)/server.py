from socket import *

s=socket(AF_INET,SOCK_STREAM)
print('This is server end! Address of this server is %s\n'%gethostname())


def recvmsg():
    data=c.recv(1000)
    while(len(data)!=0):
        print('>>', data)
        data=c.recv(1024)



s.bind((gethostname(),1991))
s.listen(5)
while True:    
    print('Waiting for connection...')
    c,a=s.accept()
    print('Connection established with client %s'%a[0])
    recvmsg()

s.close()
    
