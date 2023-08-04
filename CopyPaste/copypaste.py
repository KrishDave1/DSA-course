import pyautogui
import time 

time.sleep(15)
for line in open("typing-data.txt", "r"):
    pyautogui.typewrite(line)
