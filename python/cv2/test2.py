import cv2,time
import matplotlib.pyplot as plt
cv2= cv2.cv2
cap = cv2.VideoCapture(cv2.CAP_DSHOW)

pas = str(input('Enter your password:'))

if pas == 'admin1234':
    print('Correct')
else :
    ret,frame = cap.read()
    while True:
        cv2.imshow('Frame',frame)
        if cv2.waitKey(0) == ord('q'):
            break
            
cap.release()
cv2.destroyAllWindows()
