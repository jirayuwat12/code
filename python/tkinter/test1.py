from tkinter import *

from tkinter import messagebox

top = Tk("Test")
top.geometry("200x200")
def helloCallBack():
   msg = messagebox.showinfo( "Hello Python", "Hello World")

B = Button(top, text = "Hello", command = helloCallBack)
B.place(x = 100,y = 100)

top.mainloop()
