import libs.loginportal
import libs.config
import libs.addnew
import libs.viewall
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox

class Panel():
    def __init__(self, user):
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("800x400")
        self.__panel = Label(self.__root, text="Dashboard", font=("Arial Black", 20, "bold"))
        self.__user = Label(self.__root, text="Logged in as {}".format(user))
        self.__logout = Button(self.__root, text="Logout", command=self.__logout)
        self.__about = Button(self.__root, text="About", command=self.__abt)

        # actions
        self.__Addnew = Button(self.__root, text="   Add New Entry   ", command = self.__new)
        self.__Modify = Button(self.__root, text="     Modify Entry     ")
        self.__Delete = Button(self.__root, text="      Delete Entry     ")
        self.__Search = Button(self.__root, text="      Search Entry     ")
        self.__Viewall = Button(self.__root, text="        View Entry      ", command=self.__viewall)
        self.__Dump = Button(self.__root, text="   Save Data in File  ")
        pass

    def makepanel(self):
        self.__panel.pack()
        self.__user.place(relx=0.05, rely=0.1)
        self.__logout.place(relx=0.85, rely=0.1)
        self.__about.place(relx=0.87, rely=0.9)
        self.__Addnew.place(relx=0.15, rely=0.4)
        self.__Modify.place(relx=0.70, rely=0.4)
        self.__Delete.place(relx=0.15, rely=0.5)
        self.__Search.place(relx=0.70, rely=0.5)
        self.__Viewall.place(relx=0.15, rely=0.6)
        self.__Dump.place(relx=0.70, rely=0.6)

    def deploy(self):
        self.__root.mainloop()
        pass
    pass

    def __logout(self):
        self.__root.destroy()
        lp = libs.loginportal.Portal()
        lp.makepanel()
        lp.deploy()
        pass

    def __new(self):
        panel = libs.addnew.AddNew()
        panel.makepanel()
        panel.deploy()
        pass

    def __viewall(self):
        panel = libs.viewall.ViewAll()
        panel.makepanel()
        panel.deploy()
        pass
    def __abt(self):
        messagebox.showinfo("Info", "Coded By : {}\nSubmitted To : {}\nInstitution : {}".format(libs.config.coder, libs.config.submitted_to, libs.config.institution))
        pass
    pass
