# importing local modules
import libs.config
# importing third party modules
import pymysql
# importing builtin modules
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox


# class to perform delete action for a roll number
class Delete:
    # ------------------
    #  Constructor of class to make widgets
    # ------------------
    def __init__(self):
        # making and configuring main panel (using private members)
        self.__root = Tk()
        self.__root.geometry("400x90")
        self.__root.title("Student Management Program")
        self.__root.resizable(False, False)

        # trying to connect to sql
        try:
            self.__conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)  # connecting to sql
            self.__curr = self.__conn.cursor()                 # getting mysql cursor
            pass
        except:  # this will be invoked when there is some error occurred while connecting to sql
            messagebox.showerror("Error", "Can't establish connection with database") # displaying error message
            sys.exit(1)   # exiting on error
            pass

        # declaring widgets
        self.__l = Label(self.__root, text="Roll Number ")
        self.__e = Entry(self.__root, width=35)
        self.__b = Button(self.__root, text="Delete Entry", command=self.__del)
        pass

    # ---------------------
    #  Public method for placing widgets on the panel
    # ---------------------
    def makepanel(self):
        self.__l.place(x=30, y=20)
        self.__e.place(x=110, y=20)
        self.__b.place(x=250, y=55)
        self.__e.focus()
        pass

    # ---------------------
    #  Public method to view the panel
    # ---------------------
    def deploy(self):
        self.__root.mainloop()
        pass

    # ---------------------
    # Private method to delete entry
    # ---------------------
    def __del(self):
        # getting and storing roll number
        roll_no = self.__e.get()

        # deleting text in entry field
        self.__e.delete(0, END)

        # sql statement to check if roll number exists or not
        sql_1 = "SELECT 1 FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_no)
        # sql statement to delete the tuple
        sql_2 = "DELETE FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_no)

        # trying to execute the query
        try:
            self.__curr.execute(sql_1)          # executing check query
            chk = len(self.__curr.fetchall())   # fetching all the data and counting the length
            if chk == 0:                        # checking if roll number exists or not
                messagebox.showwarning("Warning", "Roll Number {} doesn't exists".format(roll_no))  # displaying warning message
                pass
            else:
                self.__curr.execute(sql_2)      # executing delete sql query
                self.__conn.commit()            # committing changes made on connection
                messagebox.showinfo("Info", "Deleted entry for {}".format(roll_no))    # displaying information
                pass
            pass
        except:  # this will be executed if there is some error in sql or some sql injection takes place
            self.__conn.rollback()     # rolling back changes
            messagebox.showerror("Error", "Can't Execute the query")   # showing error message
            pass
        self.__conn.close()  # closing mysql connection
        pass
    pass
