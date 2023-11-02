# Библиотека tkinter отвечает за GUI проекта
import string
from tkinter import *
from tkinter import ttk
from tkinter import font
from tkinter.font import Font

# Библиотека для работы с медиа
from PIL import ImageTk, Image
# Библиотека для системных команд
import os
import psutil
import time
# Использую для трансформации str в dict
import json
# Многопоточность
from threading import Thread

import pdb

win = Tk()

win.title("CoakValley")
win.attributes('-fullscreen', True)
win["background"] = "blue"

screen_width = 1200
screen_height = 900
vh = screen_height / 100
vw = screen_width / 100
font_size = 10
font_name = "MS Gothic"
my_font = Font(name=font_name, size=font_size*2)

def make_dialog_window(id):
    file_open = open("dialogs/" + str(id) + ".txt", "r+")
    file = file_open.read()
    file_open.close()
    print(file)
    dialog = {
        "type": "",
        "text": "",
        "icon": "",
        "bg": "",
        "ch": []
    }
    lines = []
    i = 0
    while i < len(file):
        if file[i] == '@':
            i += 1
            new_line = dialog.copy()
            if len(lines) > 0:
                new_line = lines[len(lines)-1].copy()
            #print(new_line)
            str_r = ""
            setting_name = ""
            read_choises = False
            choises = []
            choise = ["", 0]
            number_of_spec = 0
            while True:
                c = file[i]
                match c:
                    case ':':
                        setting_name = str_r
                        str_r = ""
                        if setting_name == "ch":
                            read_choises = True
                        else:
                            read_choises = False
                    case '+':
                        if not read_choises:
                            new_line[setting_name] = str_r
                        else:
                            new_line[setting_name] = choises
                        str_r = ""
                    case '@':
                        lines.append(new_line)
                        break
                    case '\n':
                        ...
                    case other:
                        if read_choises and c == '|':
                            number_of_spec += 1
                            if number_of_spec % 2 == 0:
                                choise[1] = int(str_r)
                                str_r = str(str_r)
                                choises.append((choise[0], choise[1]))
                            else:
                                choise[0] = str_r
                            str_r = ""
                        else:
                            str_r += c
                i += 1
        i += 1
        #print("NEW LINES\n" + str(lines))
    return lines

make_dialog_window(0)



win.mainloop()

#       #include <bits/stdc++.h>
#
#       using namespace std;
#
#       int main(){
#       	freopen("gen_output.txt", "w", stdout);
#       	int a = 1;
#       	for(int i = 0; i < 10; i++){
#       		cout << a + i << endl;
#       	}
#       }
