import cv2

image = cv2.imread("temp.jpg") # 读取图片

crop = image[50:150, 50:150] # 裁剪图片（高度，宽度），先高度后宽度

cv2.imshow("Crop", crop) # 显示
cv2.waitKey() # 等待按键，为了让图片不一闪而过