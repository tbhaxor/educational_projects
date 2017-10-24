# importing local modules
import libs.config
import libs.panel
# importing built in modules
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import sys
# importing third party modules
import pymysql


# class for login portal
class Portal:
    # ------------------
    #  Constructor of class to make widgets
    # ------------------
    def __init__(self):
        # making and configuring main panel (using private members)
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("700x400")
        self.__heading = Label(self.__root, text="Admin Login Portal", font=("Arial Black", 20, "bold"))

        # declaring private variables for login section
        self.__l = Label(self.__root, text="Login Portal")
        self.__l1 = Label(self.__root, text="Username : ")
        self.__l2 = Entry(self.__root)
        self.__l3 = Label(self.__root, text="Password : ")
        self.__l4 = Entry(self.__root, show="*")
        self.__l5 = Button(self.__root, text="Login", command=self.__login)

        # declaring private variables for signup section
        self.__s = Label(self.__root, text="Signup Portal")
        self.__s1 = Label(self.__root, text="Username : ")
        self.__s2 = Entry(self.__root)
        self.__s3 = Label(self.__root, text="Password : ")
        self.__s4 = Entry(self.__root, show="*")
        self.__s5 = Button(self.__root, text="Signup", command=self.__signup)
        pass

    # ------------------
    # defining public method for placing widgets
    # ------------------
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

    # ------------------
    #  public method to view the panel
    # ------------------
    def deploy(self):
        self.__root.mainloop()
        pass

    # ------------------
    #  private method that will be invoked when user will click login button
    # ------------------
    def __login(self):
        # declaring global variables in the method
        global conn
        global curr
        global sql

        # getting value and deleting them
        username = self.__l2.get()  # getting username value from login username entry field
        password = self.__l4.get()  # getting password value from login password entry field
        self.__l2.delete(0, END)    # deleting existing value from starting till end in login username field
        self.__l4.delete(0, END)    # deleting existing value from starting till end in login password field

        # sql query to check if user exists or not
        sql = "SELECT 1 FROM `stumanage_users` WHERE `name`='{}' AND `passwd`='{}'".format(username, password)

        # trying to establish sql connection
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname) # connecting to sql
            curr = conn.cursor()  # getting sql cursor to execute queries
        except:  # this will be invoked when there is some error occurred while connecting to sql
            messagebox.showerror("Error", "Can't establish connection with database") # displaying error message box
            sys.exit(1)  # exiting program on error
            pass

        # trying to execute the sql
        try:
            curr.execute(sql)  # executing sql query here
            chk = curr.fetchall() # fetching the output

            # if length of check is == 1 it means user exists
            if len(chk) == 1:
                self.__root.destroy()  # destroying login panel
                panel = libs.panel.Panel(username)   # creating an object of Dashboard
                panel.makepanel()  # making dashboard
                panel.deploy()  # deploying the dashboard
                pass
            else:
                messagebox.showinfo("Info", "Check username and password")
                pass
            pass
        except:  # this will be executed if there is some error in sql or some sql injection takes place
            messagebox.showerror("Error", "Can't Execute the query")  # displaying error message box
            pass
        conn.close()   # closing mysql connection
        pass

    # ------------------
    #  private method that will be invoked when user will click signup button
    # ------------------
    def __signup(self):
        # declaring global variables in the method
        global conn
        global curr
        global sql

        # getting value and deleting them
        username = self.__s2.get()   # getting username value from signup username entry field
        password = self.__s4.get()   # getting username value from signup password entry field
        self.__s4.delete(0, END)     # deleting existing value from starting till end in signup username field
        self.__s2.delete(0, END)     # deleting existing value from starting till end in signup password field

        # sql query to insert new login details
        sql = "INSERT INTO `stumanage_users`(`name`, `passwd`) VALUES ('{}','{}')".format(username, password)

        # trying to connect to database
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)  # establishing connection with database
            curr = conn.cursor()  # getting sql cursor to execute queries
        except:  # this will be invoked when there is some error occurred while connecting to sql
            messagebox.showerror("Error", "Can't establish connection with database")  # displaying error message box
            sys.exit(1)  # exiting program on error
            pass

        # trying to execute the sql query
        try:
            curr.execute(sql)   # executing SQL
            conn.commit()       # committing changes made on the connection
            messagebox.showinfo("Info", "User {} has been added".format(username))  # showing information that entry has been added
            pass
        except:   # this will be executed if there is some error in sql or some sql injection takes place
            conn.rollback()       # rolling back the changes made on connection
            messagebox.showerror("Error", "Can't Execute the query")   # displaying error message
            pass
        conn.close()    # closing mysql connection
        pass
    pass
