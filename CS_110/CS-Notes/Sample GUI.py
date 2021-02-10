import tkinter

class myGui:
    def __init__(self):
        self.main_window=tkinter.Tk()
        self.main_window.title('Myfirstgui')

        self.message = "I'm a label"
        
        self.label1= tkinter.Label(self.main_window,text="Hello World")
        self.label1.pack(side="right")# decides where this is displayed on the screen

        self.label2= tkinter.Label(self.main_window,text="Goodbye")
        self.label2.pack(side = "left")# decides where this is displayed on the screen       

        self.exit_button = tkinter.Button(self.main_window,text = "Exit",command=self.exit)
        self.exit_button.pack(side="bottom")
        self.counter_button=tkinter.Button(slef.main_window,text = "Count",command=self.count)
        self.counter= 0
        self.counter_button.pack(side='bottom')
        
        tkinter.mainloop()
def main():
    myGui()
main()
