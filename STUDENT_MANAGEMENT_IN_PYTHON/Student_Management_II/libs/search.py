# importing local modules
import libs.config
# importing built in modules
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import pymysql

# class to make a search
class Search:
    def __init__(self):
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("600x450")
        self.__root.resizable(False, False)

        self.__s1 = Label(self.__root, text="Enter Roll Number ")
        self.__s2 = Entry(self.__root, width=35)
        self.__s3 = Button(self.__root, text="Search", command=self.__makesearch)
        pass

    def makepanel(self):
        self.__s1.place(x=20, y=25)
        self.__s2.place(x=130, y=25)
        self.__s3.place(x=360, y=23)

        # lifting panel to top
        self.__root.lift()
        self.__root.focus_force()
        self.__root.grab_set()
        self.__root.grab_release()
        self.__s2.focus_force()
        pass

    def __makesearch(self):
        roll_number = self.__s2.get()
        self.__s2.delete(0, END)
        sql_1 = "SELECT 1 FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_number)
        sql_2 = "SELECT * FROM `stumanage_students` WHERE `roll_no`='{}'".format(roll_number)
        try:
            conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)
            curr = conn.cursor()
            pass
        except:
            messagebox.showerror("Error", "Can't establish connection with database")
            sys.exit(1)
            pass

        try:
            curr.execute(sql_1)
            chk = len(curr.fetchall())
            if chk == 0:
                messagebox.showwarning("Warning", "Roll Number {} doesn't exists".format(roll_number))
                pass
            else:
                curr.execute(sql_2)
                data = curr.fetchall()
                self.__print(list(data[0]))
                pass

            pass
        except:
            messagebox.showerror("Error", "Can't Execute the query")
            pass
        conn.close()
        pass

    def __print(self, data):
        Label(self.__root, text="Personal Details", font=('arial', 17, "bold")).place(x=25, y=60)
        Label(self.__root, text="Student's Roll Number : {}".format(data[1])).place(x=30, y=100)
        Label(self.__root, text="Student's Name : {}".format(data[2])).place(x=30, y=120)
        Label(self.__root, text="Student's Date of Birth : {}".format(data[3])).place(x=30, y=140)
        Label(self.__root, text="Student's Email Address : {}".format(data[6])).place(x=30, y=160)
        Label(self.__root, text="Student's Contact Number : {}".format(data[7])).place(x=30, y=180)
        Label(self.__root, text="Parent's Details", font=('arial', 17, "bold")).place(x=25, y=220)
        Label(self.__root, text="Father's Name : {}".format(data[4])).place(x=30, y=260)
        Label(self.__root, text="Mother's Name : {}".format(data[5])).place(x=30, y=280)
        Label(self.__root, text="Father's Contact Number : {}".format(data[8])).place(x=300, y=260)
        Label(self.__root, text="Father's Contact Number : {}".format(data[9])).place(x=300, y=280)
        Label(self.__root, text="Other Details", font=('arial', 17, "bold")).place(x=25, y=320)
        Label(self.__root, text="Nationality : {}".format(data[11])).place(x=30, y=360)
        Label(self.__root, text="Residential Address : {}".format(data[11])).place(x=30, y=380)
        Label(self.__root, text="Remarks : {}".format(data[12])).place(x=30, y=400)
        pass

    def deploy(self):
        self.__root.mainloop()
        pass
    pass
