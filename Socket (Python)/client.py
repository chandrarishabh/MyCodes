from socket import *

print('This is client end!\n')

def sendmessage():
    print('\nWrite your message to send to server.(Type \'0\' to end connections).\n')
    m=input('>>')
    if(m=='0'):
        print('Closing connections!\n')
        s.close()
        print('Connection closed. Goodbye!')
        return 1
        
    else:
        s.sendall(m.encode('utf-8'))
        return 0
    
s = socket(AF_INET,SOCK_STREAM)
s.connect((gethostname(),1991))
print('Connection established with server!\n')
while(1):
    if(sendmessage()==1):
        break
s.close()

    
