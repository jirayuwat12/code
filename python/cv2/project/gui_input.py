from tkinter import *
import numpy as np
import cv2
cv2 = cv2.cv2
def tranf():
   imgn = ent.get()+'.jpg'
   r = cv2.imread(imgn)
   b = cv2.imread(imgn)
   h,w,c= r.shape
   r[:,:,0:2] = 0 
   b[:,:,2] = 0
   rc = r[:,50:,:]
   bc = b[:,:w-50,:]
   bcb = cv2.GaussianBlur(bc,(5,5),0)
   rcb = cv2.GaussianBlur(rc,(5,5),0)
   global result
   result = bcb[:,:,:] + rcb[:,:,:]
def show():
   tranf()
   cv2.imshow('title',result)
   cv2.waitKey(0)
   cv2.destroyAllWindows()

def exe():
   tranf()
   cv2.imwrite(ent1.get()+'.jpg',result)
info = ('Path your file','Enter the lastest file''s name')
root = Tk()

row = Frame(root)
lab = Label(row, width=20, text='Path your file', anchor='w')
ent = Entry(row)
row.pack(side=TOP, fill=X, padx=5, pady=5)
lab.pack(side=LEFT)
ent.pack(side=RIGHT, expand=YES, fill=X)

row = Frame(root)
lab1 = Label(row, width=20, text='Enter the lastest file''s name', anchor='w')
ent1 = Entry(row)
row.pack(side=TOP, fill=X, padx=5, pady=5)
lab1.pack(side=LEFT)
ent1.pack(side=RIGHT, expand=YES, fill=X)

b1 = Button(root, text='RUN', command=exe)
b1.pack(side=LEFT, padx=5, pady=5)
b2 = Button(root, text='SHOW', command=show)
b2.pack(side=LEFT, padx=5, pady=5)
b3 = Button(root, text='QUIT', command=root.quit)
b3.pack(side=LEFT, padx=5, pady=5)

root.mainloop()