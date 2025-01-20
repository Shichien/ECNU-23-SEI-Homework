import cv2

# 通过鼠标点击获取坐标
# 注册一个回调函数，当用户在窗口中按下鼠标时，会自动调用这个函数。
# 打印出鼠标点击的坐标点（相对于窗口左上角的坐标，而不是相对于图片左上角的坐标）
def on_mouse(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN: # 左键按下
        print("Mouse Position:", x, y)

def GetColor(): # 获取图片的颜色
    GetColor = image[400,400,0]
    # 获取颜色通道的值：image[X, Y, Num]，其中 0：B || 1：G || 2：R
    print("GetColor is", GetColor)

def GetSize(): # 获取图片的尺寸
    high, width, channels = image.shape
    print("High is", high, "Width is", width, "Channels is", channels)

def ShowTheCrop():
    cv2.imshow("Blue", image[20:200, 20:200, 1])
    # imshow 展示函数，展示从哪里到哪里，展示哪个通道

def FillTheColor():
    # 第一种方法
    image[20:200, 20:200, 2] = GetColor  # 把区域内的所有像素都修改为红色

    # 第二种方法
    for i in range(241, 292):  # i表示横坐标，在区间[241, 291]内取值
        for j in range(168, 219):  # j表示纵坐标，在区间[168, 218]内取值
            image[i, j] = [255, 255, 255]  # 把区域内的所有像素都修改为白色


cv2.namedWindow("Image")
cv2.setMouseCallback("Image", on_mouse)

image = cv2.imread("temp.jpg")

# 显示图像
while True:
   cv2.imshow('Point Coordinates', image)
   k = cv2.waitKey(1) & 0xFF
   if k == 27:
      break
cv2.destroyAllWindows()  # 关闭所有的窗口时，销毁所有窗口