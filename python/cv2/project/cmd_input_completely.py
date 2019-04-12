import numpy as np
import cv2
cv2 = cv2.cv2
imgn= str(input("Enter img name>>"))
imgn3d = str(input("Enter last file name>>"))
#imgn = 'test_copy.jpg'
#read img
img = cv2.imread(imgn)
r = cv2.imread(imgn)
b = cv2.imread(imgn)
#h,w,c= img.shape()
print(img.shape)
#cvt img to red,cyan
r[:,:,0:2] = 0 
b[:,:,2] = 0
#crop img 
rc = r[:,50:,:]
bc = b[:,:w-50,:]
#blur img 
bcb = cv2.GaussianBlur(bc,(5,5),0)
rcb = cv2.GaussianBlur(rc,(5,5),0)
#last list for 3D img
result = bcb[:,:,:] + rcb[:,:,:]
#list 3D img
print(result)
#show img
cv2.imshow('title',result)
#save 3D img
#cv2.imwrite(imgn3d,result)
#end process
cv2.waitKey(0)
cv2.destroyAllWindows()