# importing local modules
import libs.loginportal
import libs.config
import libs.addnew
import libs.viewall
import libs.delete
import libs.search
import libs.modify
# importing built in modules
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox


# class for creating a Dashboard
class Panel:
    # ------------------
    #  Constructor of class to make widgets
    # ------------------
    def __init__(self, user):  # getting the currently logged user name
        # making and configuring main panel (using private members)
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("800x400")

        # making default widgets
        self.__panel = Label(self.__root, text="Dashboard", font=("Arial Black", 20, "bold"))       # main banner
        self.__user = Label(self.__root, text="Logged in as {}".format(user))                       # making a label for viewing current user logged in
        self.__logout = Button(self.__root, text="Logout", command=self.__logout)                   # logout button
        self.__about = Button(self.__root, text="           About           ", command=self.__abt)  # about button to display the coder's name and all

        # Creating different buttons for different Actions
        self.__Addnew = Button(self.__root, text="   Add New Entry   ", command=self.__new)
        self.__Modify = Button(self.__root, text="     Modify Entry     ", command=self.__mod)
        self.__Delete = Button(self.__root, text="      Delete Entry     ", command=self.__del)
        self.__Search = Button(self.__root, text="      Search Entry     ", command=self.__search)
        self.__Viewall = Button(self.__root, text="        View Entry      ", command=self.__viewall)
        pass

    # ------------------
    # defining public method for placing widgets
    # ------------------
    def makepanel(self):
        self.__panel.pack()
        self.__user.place(relx=0.05, rely=0.1)
        self.__logout.place(relx=0.85, rely=0.1)
        self.__Addnew.place(relx=0.15, rely=0.4)
        self.__Modify.place(relx=0.70, rely=0.4)
        self.__Delete.place(relx=0.15, rely=0.5)
        self.__Search.place(relx=0.70, rely=0.5)
        self.__Viewall.place(relx=0.15, rely=0.6)
        self.__about.place(relx=0.70, rely=0.6)

    # ------------------
    #  public method to view the panel
    # ------------------
    def deploy(self):
        self.__root.mainloop()
        pass
    pass

    # ------------------
    #  private method that will be invoked when user wants to logout
    # ------------------
    def __logout(self):
        self.__root.destroy()  # destroying current panel
        lp = libs.loginportal.Portal()   # creating object of login portal
        lp.makepanel()                   # making panel
        lp.deploy()                      # deploying the panel
        pass

    # ------------------
    #  private method that will be invoked when user wants to add a new entry
    # ------------------
    def __new(self):
        panel = libs.addnew.AddNew()  # creating object
        panel.makepanel()             # making panel
        panel.deploy()                # deploying panel
        pass

    # ------------------
    #  private method that will be invoked when user wants to fetch the details of all the students
    # ------------------
    def __viewall(self):
        panel = libs.viewall.ViewAll()  # creating object
        panel.makepanel()               # making panel
        panel.deploy()                  # deploying panel
        pass

    # ------------------
    #  private method that will be invoked when user wants to fetch the details of all the students
    # ------------------
    def __del(self):
        panel = libs.delete.Delete()   # creating object
        panel.makepanel()              # making panel
        panel.deploy()                 # deploying panel
        pass

    # ------------------
    #  private method that will be invoked when user wants to fetch the details of all the students
    # ------------------
    def __search(self):
        panel = libs.search.Search()   # creating object
        panel.makepanel()              # making panel
        panel.deploy()                 # deploying panel
        pass

    # ------------------
    #  private method that will be invoked when user wants to modify the details
    # ------------------
    def __mod(self):
        panel = libs.modify.Modify()   # creating object
        panel.makepanel()              # making panel
        panel.deploy()                 # deploying panel
        pass

    # ------------------
    #  private method that will be invoked when user wants to check the details that who coded
    # ------------------
    def __abt(self):
        # displaying message_box
        messagebox.showinfo("Info", "Coded By : {}\nSubmitted To : {}\nInstitution : {}".format(libs.config.coder, libs.config.submitted_to, libs.config.institution))
        pass
    pass
