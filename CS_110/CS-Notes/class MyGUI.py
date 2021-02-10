import tkinter

class MyGUI:
	def __init__(self):
		self.main_window=tkinter.Tk()
        self.main_window.title('MyFirstGUI')
        self.label1 = tkinter.Label(self.main_window,text="Hello World")
        self.label1.pack(side= "right")
        self.change_button = tkinter.Button(self.main_window,text = "Change Label",command=self.change_label)
        self.change_button.pack(side="bottom")


