import libs.config
import libs.viewall
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import pymysql


class AddNew():
    def __init__(self):
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("600x450")
        self.__root.resizable(False, False)
        try:
            self.__conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass,
                                          libs.config.dbname)
            self.__curr = self.__conn.cursor()
            pass
        except:
            messagebox.showerror("Error", "Can't establish connection with database")
            sys.exit(1)
            pass

        # widgets
        self.__l1 = Label(self.__root, text="Roll Number")
        self.__l2 = Label(self.__root, text="Student's Name")
        self.__l3 = Label(self.__root, text="Student's DOB")
        self.__l3 = Label(self.__root, text="Student's Email")
        self.__l4 = Label(self.__root, text="Student's Contact Number")
        self.__l5 = Label(self.__root, text="Father's Name")
        self.__l6 = Label(self.__root, text="Father's Contact Number")
        self.__l7 = Label(self.__root, text="Mother's Name")
        self.__l8 = Label(self.__root, text="Mother's Contact Number")
        self.__l9 = Label(self.__root, text="Nationality")
        self.__l10 = Label(self.__root, text="Address")
        self.__l11 = Label(self.__root, text="Remarks")
        self.__val1 = StringVar()
        self.__val2 = StringVar()
        self.__val3 = StringVar()
        self.__val4 = StringVar()
        self.__val5 = StringVar()
        self.__val6 = StringVar()
        self.__val7 = StringVar()
        self.__val8 = StringVar()
        self.__val9 = StringVar()
        self.__val10 = StringVar()
        self.__val11 = StringVar()
        self.__e1 = Entry(self.__root, width=35, textvariable=self.__val1)
        self.__e2 = Entry(self.__root, width=35, textvariable=self.__val2)
        self.__e3 = Entry(self.__root, width=35, textvariable=self.__val3)
        self.__e4 = Entry(self.__root, width=35, textvariable=self.__val4)
        self.__e5 = Entry(self.__root, width=35, textvariable=self.__val5)
        self.__e6 = Entry(self.__root, width=35, textvariable=self.__val6)
        self.__e7 = Entry(self.__root, width=35, textvariable=self.__val7)
        self.__e8 = Entry(self.__root, width=35, textvariable=self.__val8)
        self.__e9 = Entry(self.__root, width=35, textvariable=self.__val9)
        self.__e10 = Entry(self.__root, width=35, textvariable=self.__val10)
        self.__e11 = Entry(self.__root, width=35, textvariable=self.__val11)
        self.__add = Button(self.__root, text="             Add New             ", command=self.__add)

        pass

    def makepanel(self):
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
        self.__add.place(x=230, y=350)
        pass

    def __add(self):
        global sql
        sql = "INSERT INTO `stumanage_students`(`roll_no`, `name`, `dob`, `father_name`, `mother_name`, `email`, `contact_number`, `father_c_number`, `mother_c_number`, `nationality`, `address`, `remarks`) VALUES ('{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}') ".format(self.__val1.get(), self.__val2.get(), self.__val3.get(), self.__val5.get(), self.__val7.get(), self.__val3.get(), self.__val4.get(), self.__val6.get(), self.__val8.get(), self.__val9.get(), self.__val10.get(), self.__val11.get())
        try:
            self.__curr.execute(sql)
            self.__conn.commit()
            messagebox.showinfo("Info", "New entry added")
        except:
            self.__conn.rollback()
            messagebox.showerror("Error", "Can't run query")
        self.__conn.close()
        pass

    def deploy(self):
        self.__root.mainloop()
        pass

    pass
