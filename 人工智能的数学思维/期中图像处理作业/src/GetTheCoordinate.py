# 导入所需的库
import cv2


# 显示在图像上单击的点的坐标的功能
def click_event(event, x, y, flags, params):
    # 检查左键点击
    if event == cv2.EVENT_LBUTTONDOWN:
        print('左键点击')
        print(f'({x},{y})')

        # 在图像上把坐标作为文本显示
        cv2.putText(img, f'({x},{y})', (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)
        cv2.circle(img, (x, y), 3, (0, 0, 255), -1)

    if event == cv2.EVENT_RBUTTONDOWN:
        print('右键点击')
        print(f'({x},{y})')

        # 在图像上把坐标作为文本显示
        cv2.putText(img, f'({x},{y})', (x, y),  # 注意第二个值是竖坐标
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2)
        cv2.circle(img, (x, y), 3, (0, 0, 255), -1)


# 读取输入图像
img = cv2.imread('temp.jpg')

# 创建一个窗口
cv2.namedWindow('Point Coordinates')

# 将回调函数绑定到窗口
cv2.setMouseCallback('Point Coordinates', click_event)

# 显示图像
while True:
    cv2.imshow('Point Coordinates', img)
    k = cv2.waitKey(1) & 0xFF
    if k == 27: # Esc 的键值为 27
        break
cv2.destroyAllWindows()