import sys
from socket import *
from tkinter import *
from multiprocessing import Process
counterRec=-1
rocket=0
s=socket(AF_INET,SOCK_STREAM)
s.bind((gethostname(),19991))
s.listen(5)
c,a=s.accept()
print('established connection')
counter=-1
def listener():
    data=c.recv(1024)
    while(len(data)!=0):
        window.update()
        chatlist.insert(counter+1,data)
        data=c.recv(1024)
            
def send():
    INPUT=entry.get()
    chatlist.insert(counter+1,INPUT)
    window.update()
    chatinput.delete(0,END)

#creating window
window = Tk()
window.geometry('450x600')
window.title('LanChat')
appLabel=Label(window,text='LanChat',font=45)
appLabel.pack()

chatlist = Listbox(window,width=40,font=30)
chatlist.pack()

entry=StringVar()
chatinput=Entry(window,width=40,font=30,textvariable=entry)
chatinput.pack()

sendButton = Button(window,text='SEND',font=30,width=35,command=send)
sendButton.pack()

listener()
