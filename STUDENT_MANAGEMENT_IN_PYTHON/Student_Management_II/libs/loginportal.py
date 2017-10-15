from tkinter import *


class Login():
    def __init__(self):
        self.root = Tk()
        self.root.title("Student Management Program")
        self.root.geometry("700x400")
        self.heading = Label(self.root, text="Admin Login Portal", font=("Arial Black", 20, "bold"))
        # for login
        self.l = Label(self.root, text="Login Portal", fg="red")
        self.l1 = Label(self.root, text="Username : ")
        self.l2 = Entry(self.root)
        self.l3 = Label(self.root, text="Password : ")
        self.l4 = Entry(self.root, show="*")
        self.l5 = Button(self.root, text="Login", height=1, width=15)

        # for signup
        self.s = Label(self.root, text="Signup Portal", fg="red")
        self.s1 = Label(self.root, text="Username : ")
        self.s2 = Entry(self.root)
        self.s3 = Label(self.root, text="Password : ")
        self.s4 = Entry(self.root, show="*")
        self.s5 = Button(self.root, text="Signup", height=1, width=15)
        pass

    def makepanel(self):
        self.heading.pack()
        self.l.place(relx=0.1, rely=0.2)
        self.l1.place(relx=0.05, rely=0.3)
        self.l2.place(relx=0.15, rely=0.3)
        self.l3.place(relx=0.05, rely=0.4)
        self.l4.place(relx=0.15, rely=0.4)
        self.l5.place(relx=0.12, rely=0.5)
        self.s.place(relx=0.7, rely=0.2)
        self.s1.place(relx=0.65, rely=0.3)
        self.s2.place(relx=0.75, rely=0.3)
        self.s3.place(relx=0.65, rely=0.4)
        self.s4.place(relx=0.75, rely=0.4)
        self.s5.place(relx=0.72, rely=0.5)

        pass

    def show(self):
        self.root.mainloop()
        pass

    pass
