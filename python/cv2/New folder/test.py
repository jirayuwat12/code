import numpy as np
from tkinter import *
import cv2
def camera():
    cap = cv2.VideoCapture(0)   
    ret, frame = cap.read()
    h,w,c = frame.shape
    while(True):
    # Capture frame-by-frame
        ret, red = cap.read()
        ret, cyan =cap.read()
        red[:,:,:2] = 0
        cyan[:,:,2:] = 0
        redc = red[:,10:,:]
        cyanc = cyan[:,:w-10,:]
        res = redc + cyanc
    # Our operations on the frame come here
    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # Display the resulting frame
        cv2.imshow('frame',res)
        a = cv2.waitKey(1) 
        if  a == ord('q'):
            break
        if a == ord('s'):
            cv2.imwrite(x +'.jpg',res)
            break
    # When everything done, release the capture
    cap.release()
    cv2.destroyAllWindows()
def click():
    global x
    x = entry.get()
    camera()
root = Tk()
entry = Entry(root,bg ='black',fg = 'white')
entry.pack(side = 'left')
button = Button(root,text = 'Enter', fg = "white", bg = "pink",command = click)
button.pack(side='right')
root.mainloop()