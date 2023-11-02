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
font_size = 50
font_name = "MS Gothic"
my_font = Font(name=font_name, size=font_size*2)



def fit_text_in_box(text: string, font: Font, width: float, height: float):
    gen_text = ""
    last_line = ""
    new_word = ""
    one_line_height = font.metrics('linespace')
    number_of_lines = 1
    i = 0
    while i < len(text):
        #print('\n' + str(i))
        need_space = ''
        need_paragraph = ''
        if not last_line == "":
            need_space = ' '
        if not gen_text == "":
            need_paragraph = '\n'
        if text[i] == ' ':
            #print("A", end="")
            if font.measure(last_line+need_space+new_word) <= width:
                #print("B", end="")
                #print(1)
                last_line += need_space + new_word
                new_word = ""
            else:
                #print("C", end="")
                if font.measure(new_word) > width:
                    i = -1
                    last_line = ""
                    gen_text = ""
                    new_word = ""
                    font["size"] -= 1
                    number_of_lines = 1
                    one_line_height = font.metrics('linespace')
                else:
                    gen_text += need_paragraph + last_line
                    last_line = new_word
                    new_word = ""
                    number_of_lines += 1
        else:
            #print("D", end="")
            new_word += text[i]
        if i + 1 == len(text):
            if font.measure(last_line+need_space+new_word) <= width:
                last_line += need_space + new_word
                gen_text += '\n' + last_line
                number_of_lines += 1
            else:
                gen_text += '\n' + last_line
                last_line = new_word
                if font.measure(last_line) > width:
                    i = -1
                    last_line = ""
                    gen_text = ""
                    new_word = ""
                    font["size"] -= 1
                    number_of_lines = 1
                    one_line_height = font.metrics('linespace')
                else:
                    gen_text += '\n' + last_line
                    number_of_lines += 1
        if number_of_lines * one_line_height > height:
            #print("F", end="")
            i = -1
            last_line = ""
            gen_text = ""
            new_word = ""
            font["size"] -= 1
            number_of_lines = 1
            one_line_height = font.metrics('linespace')
        i += 1
        #print("\nCUR GEN_TEXT:\n" + gen_text + "\nCUR LAST_LINE:\n" + last_line + "\nCUR NEW_WORD:\n" + new_word)
    return gen_text, font


text = "А я и не хотела больше aaaaaa aaaaaaaaa никуда идти aaaaaaaa aaaaaaaaa aaaaaaa aaaaaaaaaaaaa aaaaaa aaaa aaa aaaaaa"


args = fit_text_in_box(text, my_font, 30*vw, 20*vh)
print(args)
example = Button(text=args[0], borderwidth=0, highlightthickness=0, relief=FLAT, bg="black", activebackground="black", activeforeground="#17FF00", fg="#17FF00", font=args[1])
example.place(x=10*vw, y=10*vh, width=30*vw, height=20*vh)

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
