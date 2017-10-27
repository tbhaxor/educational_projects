# importing local modules
import libs.config
# importing built in modules
from tkinter import *
from tkinter import messagebox
from tkinter.ttk import *
# importing third party modules
import pymysql


# class for adding new
class AddNew:
    # ---------------------
    #  Constructing AddNew Class
    # ---------------------
    def __init__(self):
        # declaring panel and configuring them
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("600x450")
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
        self.__add = Button(self.__root, text="             Add New             ", command=self.__add)
        pass

    # ---------------------
    #  Public method for placing widgets on the panel
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
        self.__add.place(x=230, y=370)

        # lifting panel to top
        self.__root.lift()
        self.__root.focus_force()
        self.__root.grab_set()
        self.__root.grab_release()
        pass

    # ---------------------
    #  Private method of the class to add new entry
    # ---------------------
    def __add(self):
        # getting values from entry fields and storing in local variables
        roll_no = self.__e1.get()
        name = self.__e2.get()
        dob = self.__e3.get()
        email = self.__e4.get()
        cnum = self.__e5.get()
        fname = self.__e6.get()
        fcnum = self.__e7.get()
        mname = self.__e8.get()
        mcnum = self.__e9.get()
        nationality = self.__e10.get()
        address = self.__e11.get()
        remarks = self.__e12.get()

        # deleting the entry fields
        self.__e1.delete(0, END)
        self.__e2.delete(0, END)
        self.__e3.delete(0, END)
        self.__e4.delete(0, END)
        self.__e5.delete(0, END)
        self.__e6.delete(0, END)
        self.__e7.delete(0, END)
        self.__e8.delete(0, END)
        self.__e9.delete(0, END)
        self.__e10.delete(0, END)
        self.__e11.delete(0, END)
        self.__e12.delete(0, END)

        # sql to check if roll number exists or not
        sql_1 = "SELECT 1 FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_no)
        # sqk to insert new entry
        sql_2 = "INSERT INTO `stumanage_students`(`roll_no`, `name`, `dob`, `father_name`, `mother_name`, `email`, " \
                "`contact_number`, `father_c_number`, `mother_c_number`, `nationality`, `address`, `remarks`) VALUES " \
                "('{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}') ".format(roll_no, name, dob, fname, mname, email, cnum,fcnum,mcnum,nationality,address,remarks)

        # trying to connect to mysql
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname) # connecting to mysql
            curr = conn.cursor()    # assigning mysql cursor
            pass
        except:  # this will be invoked when there is some error occurred while connecting to sql
            messagebox.showerror("Error", "Can't establish connection with database")    # displaying error message box
            sys.exit(1)       # exiting program on error
            pass

        # trying to execute the query
        try:
            curr.execute(sql_1)           # executing the check statement
            chk = len(curr.fetchall())    # fetching all data and counting
            if chk > 0:      # checks whether roll number exists or not
                messagebox.showwarning("Warning", "Entry for {} has already been added".format(roll_no))     # showing warning message
                pass
            else:
                curr.execute(sql_2)          # inserting values in the table
                conn.commit()                # committing changes to the connection
                messagebox.showinfo("Info", "New entry for {} has been added".format(roll_no))    # showing info message
            pass
        except:      # this will be executed if there is some error in sql or some sql injection takes place
            messagebox.showerror("Error", "Can't run query")   # displaying error messagebox
            sys.exit(1)                                        # exiting system on error
            pass
        conn.close()    # closing mysql connection
        pass

    # ---------------------
    #  Public method of the class to show the panel
    # ---------------------
    def deploy(self):
        self.__root.mainloop()
        pass

    pass
