import cv2,time
from matplotlib import pyplot as plt 
from copy import deepcopy
import os
cv2  = cv2.cv2
#input img name
picname = input("Enter image's name :")
ck = os.path.isfile(picname)
#loop input if invalid img name
while not ck:
    picname = input("Enter image's name :")
    ck = os.path.isfile(picname)
#make R,G and B img file
img =cv2.imread(picname)
r = cv2.imread(picname)
g = cv2.imread(picname)
b = cv2.imread(picname)
g[:,:,0] = 0
g[:,:,2] = 0
b[:,:,2] = 0 
b[:,:,1] = 0 
r[:,:,0] = 0 
r[:,:,1] = 0
#drawimg img
fig,ax = plt.subplots(ncols=2,nrows=2)
ax[0,0].imshow(img)
ax[0,1].imshow(r)
ax[1,0].imshow(g)
ax[1,1].imshow(b)
plt.show()
    
#end process
cv2.waitKey(0)
cv2.destroyAllWindows()
os.system('cls')