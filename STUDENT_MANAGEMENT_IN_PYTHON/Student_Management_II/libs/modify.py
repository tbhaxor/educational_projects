# importing local module
import libs.config
# importing built in module
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import pymysql
import sys


# Class for Modifying the Entry
class Modify:
    # ---------------------
    #  Constructing Modify Class
    # ---------------------
    def __init__(self):
        # declaring panel and configuring them
        self.__root = Tk()
        self.__root.geometry("700x400")
        self.__root.title("Student Management Program")
        self.__root.resizable(False, False)

        # declaring widgets
        self.__l1 = Label(self.__root, text="Roll Number")
        self.__l2 = Label(self.__root, text="Student's Name")
        self.__l3 = Label(self.__root, text="Student's DOB")
        self.__l4 = Label(self.__root, text="Student's Email")
        self.__l5 = Label(self.__root, text="Student's Contact Number")
        self.__l6 = Label(self.__root, text="Father's Name")
        self.__l7 = Label(self.__root, text="Father's Contact Number")
        self.__l8 = Label(self.__root, text="Mother's Name")
        self.__l9 = Label(self.__root, text="Mother's Contact Number")
        self.__l10 = Label(self.__root, text="Nationality")
        self.__l11 = Label(self.__root, text="Address")
        self.__l12 = Label(self.__root, text="Remarks")
        self.__e1 = Entry(self.__root, width=35)
        self.__e2 = Entry(self.__root, width=35)
        self.__e3 = Entry(self.__root, width=35)
        self.__e4 = Entry(self.__root, width=35)
        self.__e5 = Entry(self.__root, width=35)
        self.__e6 = Entry(self.__root, width=35)
        self.__e7 = Entry(self.__root, width=35)
        self.__e8 = Entry(self.__root, width=35)
        self.__e9 = Entry(self.__root, width=35)
        self.__e10 = Entry(self.__root, width=35)
        self.__e11 = Entry(self.__root, width=35)
        self.__e11 = Entry(self.__root, width=35)
        self.__e12 = Entry(self.__root, width=35)
        self.__update = Button(self.__root, text="             Update             ", command=self.__up)
        self.__show = Button(self.__root, text="      Select      ", command=self.__sel)
        pass

    # ---------------------
    #  Public method to place widgets on the panel
    # ---------------------
    def makepanel(self):
        # placing all the labels
        self.__l1.place(x=10, y=10)
        self.__l2.place(x=10, y=40)
        self.__l3.place(x=10, y=70)
        self.__l4.place(x=10, y=100)
        self.__l5.place(x=10, y=130)
        self.__l6.place(x=10, y=160)
        self.__l7.place(x=10, y=190)
        self.__l8.place(x=10, y=220)
        self.__l9.place(x=10, y=250)
        self.__l10.place(x=10, y=280)
        self.__l11.place(x=10, y=310)
        self.__l12.place(x=10, y=340)

        # placing all the entry fields
        self.__e1.place(x=200, y=10)
        self.__e2.place(x=200, y=40)
        self.__e3.place(x=200, y=70)
        self.__e4.place(x=200, y=100)
        self.__e5.place(x=200, y=130)
        self.__e6.place(x=200, y=160)
        self.__e7.place(x=200, y=190)
        self.__e8.place(x=200, y=220)
        self.__e9.place(x=200, y=250)
        self.__e10.place(x=200, y=280)
        self.__e11.place(x=200, y=310)
        self.__e12.place(x=200, y=340)

        # placing the button
        self.__show.place(x=450, y=8)
        self.__update.place(x=230, y=370)

        # lifting panel to top
        self.__root.lift()
        self.__root.focus_force()
        self.__root.grab_set()
        self.__root.grab_release()
        pass

    # ---------------------
    #  Private method to select data and display in entry fields
    # ---------------------
    def __sel(self):
        # getting roll number
        roll_no = self.__e1.get()

        # sql queries
        sql_1 = "SELECT 1 FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_no)   # query to check whether roll number exists or not
        sql_2 = "SELECT * FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_no)   # query to select data

        # trying to connect to the db
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)  # connecting to mysql
            curr = conn.cursor()             # getting mysql cursor
            pass
        except:  # this will be invoked when there is some error occurred while connecting to sql
            messagebox.showerror("Error", "Can't establish connection with database")  # displaying error message box
            sys.exit(1)  # exiting program on error
            pass

        # trying to execute queries
        try:
            curr.execute(sql_1)          # executing check query
            chk = len(curr.fetchall())   # fetching and counting rows
            if chk == 0:
                messagebox.showwarning("Warning", "Roll Number {} doesn't exists".format(roll_no))
                pass
            else:
                curr.execute(sql_2)                   # selecting and displaying values
                data = list(curr.fetchall()[0])
                self.__e2.insert(0, data[2])
                self.__e3.insert(0, data[3])
                self.__e4.insert(0, data[6])
                self.__e5.insert(0, data[7])
                self.__e6.insert(0, data[4])
                self.__e7.insert(0, data[8])
                self.__e8.insert(0, data[5])
                self.__e9.insert(0, data[9])
                self.__e10.insert(0, data[10])
                self.__e11.insert(0, data[11])
                self.__e12.insert(0, data[12])
                pass
            pass
        except:  # this will be executed if there is some error in sql or some sql injection takes place
            messagebox.showerror("Error", "Can't Run Query")  # displaying error messages
            pass
        pass

    # ---------------------
    #  Public method to display panel
    # ---------------------
    def deploy(self):
        self.__root.mainloop()
        pass

    # ---------------------
    #  Private method to save changes
    # ---------------------
    def __up(self):
        # getting values
        roll_number = self.__e1.get()
        name = self.__e2.get()
        dob = self.__e3.get()
        email = self.__e4.get()
        snum = self.__e5.get()
        fname = self.__e6.get()
        fcnum = self.__e7.get()
        mname = self.__e8.get()
        mcnum = self.__e9.get()
        na = self.__e10.get()
        adr = self.__e11.get()
        rem = self.__e12.get()

        # sql query to update values
        sql = "UPDATE `stumanage_students` SET `name`='{}',`dob`='{}',`father_name`='{}',`mother_name`='{}',`email`='{}',`contact_number`='{}',`father_c_number`='{}',`mother_c_number`='{}',`nationality`='{}',`address`='{}',`remarks`='{}' WHERE `roll_no`='{}'".format(
            name, dob, fname, mname, email, snum, fcnum, mcnum, na, adr, rem, roll_number)

        # trying connecting to mysql
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname) # connecting to mysql
            curr = conn.cursor()              # getting mysql cursor
            pass
        except:  # this will be invoked when there is some error occurred while connecting to sql
            messagebox.showerror("Error", "Can't establish connection with database")  # displaying error message box
            sys.exit(1)  # exiting program on error
            pass

        # trying to execute the query
        try:
            curr.execute(sql)     # executing update query
            conn.commit()         # committing changes on
            messagebox.showinfo("Info", "Data for roll number {} has been modified".format(roll_number))  # displaing error message
            pass
        except:   # this will be executed if there is some error in sql or some sql injection takes place
            conn.rollback()   # rolling back the changes
            messagebox.showerror("Error", "Can't Run Query")        # displaying error message
            pass
        conn.close()         # closing mysql connection
        pass

    pass
