import cv2
cap = cv2.VideoCapture(0)
#h,w,c = frame.shape
while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    buff = gray
    gray[::] = gray[::] - buff[::]
    cv2.imshow('frame',gray)
    a = cv2.waitKey(1)
    if  a == ord('q'):
        break
    if a == ord('s'):
        cv2.imwrite(x +'.jpg',gray)
# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
