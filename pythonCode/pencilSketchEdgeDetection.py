import cv2
import sys

#read image
image = cv2.imread("../assets/anish.jpg")

#check if images exists
if image is None:
    print("can not find image")
    sys.exit()

#convert to gray scale
output = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

#Apply gaussian blur
output = cv2.GaussianBlur(output, (3,3), 0)

#detect edges in the image
output = cv2.Laplacian(output, -1, ksize=5)

#invert the binary image
output = 255 - output

#binary thresholding
ret, output = cv2.threshold(output, 150, 255, cv2.THRESH_BINARY)

#create widnows to dispplay images
cv2.namedWindow("image", cv2.WINDOW_AUTOSIZE)
cv2.namedWindow("pencilsketch", cv2.WINDOW_AUTOSIZE)

#display images
cv2.imshow("image", image)
cv2.imshow("pencilsketch", output)

#press esc to exit the program
cv2.waitKey(0)

#close all the opened windows
cv2.destroyAllWindows()