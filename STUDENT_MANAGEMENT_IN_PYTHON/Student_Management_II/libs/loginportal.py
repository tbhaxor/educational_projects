import libs.config
import libs.panel
from tkinter import *
from tkinter import messagebox
import pymysql
import sys


class Portal():
    def __init__(self):
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("700x400")
        self.__heading = Label(self.__root, text="Admin Login Portal", font=("Arial Black", 20, "bold"))
        # for login
        self.__l = Label(self.__root, text="Login Portal", fg="red")
        self.__l1 = Label(self.__root, text="Username : ")
        self.__lUser = StringVar()
        self.__l2 = Entry(self.__root, textvariable = self.__lUser)
        self.__l3 = Label(self.__root, text="Password : ")
        self.__lPass = StringVar()
        self.__l4 = Entry(self.__root, show="*", textvariable = self.__lPass)
        self.__l5 = Button(self.__root, text="Login", height=1, width=15, command=self.__login)
        # for signup
        self.__s = Label(self.__root, text="Signup Portal", fg="red")
        self.__s1 = Label(self.__root, text="Username : ")
        self.__sUser = StringVar()
        self.__s2 = Entry(self.__root, textvariable = self.__sUser)
        self.__s3 = Label(self.__root, text="Password : ")
        self.__sPass = StringVar()
        self.__s4 = Entry(self.__root, show="*", textvariable = self.__sPass)
        self.__s5 = Button(self.__root, text="Signup", height=1, width=15, command=self.__signup)
        pass

    def makepanel(self):
        self.__heading.pack()
        self.__l.place(relx=0.1, rely=0.2)
        self.__l1.place(relx=0.05, rely=0.3)
        self.__l2.place(relx=0.15, rely=0.3)
        self.__l3.place(relx=0.05, rely=0.4)
        self.__l4.place(relx=0.15, rely=0.4)
        self.__l5.place(relx=0.12, rely=0.5)
        self.__s.place(relx=0.7, rely=0.2)
        self.__s1.place(relx=0.65, rely=0.3)
        self.__s2.place(relx=0.75, rely=0.3)
        self.__s3.place(relx=0.65, rely=0.4)
        self.__s4.place(relx=0.75, rely=0.4)
        self.__s5.place(relx=0.72, rely=0.5)
        pass

    def deploy(self):
        self.__root.mainloop()
        pass
    
    def __login(self):
        global conn
        global curr
        global sql
        u = self.__lUser.get()
        p = self.__lPass.get()
        self.__l2.delete(0, END)
        self.__l4.delete(0, END)
        sql = "SELECT 1 FROM `stumanage_users` WHERE `name`='{}' AND `passwd`='{}'".format(u , p)
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)
            curr = conn.cursor()
        except:
            messagebox.showerror("Error", "Can't establish connection with database")
            sys.exit(1)
            pass
        try:
            curr.execute(sql)
            chk = curr.fetchall()
            if len(chk) == 1:
                self.__root.destroy()
                panel = libs.panel.Panel()
                panel.makepanel()
                panel.deploy()
                pass
            else:
                messagebox.showinfo("Info", "Check username and password")
                pass
            pass
        except:
            messagebox.showerror("Error", "Can't Execute the query")
            pass
        conn.close()
        pass

    def __signup(self):
        global conn
        global curr
        global sql
        u = self.__sUser.get()
        p = self.__sPass.get()
        self.__s2.delete(0, END)
        self.__s4.config(0, END)
        self.__l2.focus()
        sql = "INSERT INTO `stumanage_users`(`name`, `passwd`) VALUES ('{}','{}')".format(u, p)
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)
            curr = conn.cursor()
        except:
            messagebox.showerror("Error", "Can't establish connection with database")
            sys.exit(1)
            pass
        try:
            curr.execute(sql)
            conn.commit()
            messagebox.showinfo("Info", "User {} has been added".format(u))
            pass
        except:
            conn.rollback()
            messagebox.showerror("Error", "Can't Execute the query")
            pass
        conn.close()
        pass
    pass
