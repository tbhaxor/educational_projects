import libs.loginportal
import libs.config
from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import pymysql
import sys


class ViewAll():
    def __init__(self):
        self.__root = Tk()
        self.__root.title("Student Management Program")
        self.__root.geometry("1310x630")
        self.__root.resizable(False, False)
        try:
            self.__conn = pymysql.connect(libs.config.dbhost, libs.config.dbuser, libs.config.dbpass, libs.config.dbname)
            self.__curr = self.__conn.cursor()
            pass
        except:
            messagebox.showerror("Error", "Can't establish connection with database")
            sys.exit(1)
            pass

        pass

    def makepanel(self):
        data = self.__get_data()
        cols = self.__get_cols()
        tree = Treeview(self.__root, columns=cols, height=30)
        tree.column("#0", width=0)
        for x in cols:
            tree.column(x, width=100, anchor=CENTER)
            tree.heading(x, text=x)
            pass

        for x in data:
            tree.insert("", 0, text="Line 1", values=x)
            pass
        tree.pack()

        # lifting panel to top
        self.__conn.close()
        self.__root.lift()
        self.__root.focus_force()
        self.__root.grab_set()
        self.__root.grab_release()
        pass

    def deploy(self):
        self.__root.mainloop()
        pass

    def __get_cols(self):
        cols = []
        try:
            sql = "SELECT column_name FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME='stumanage_students'"
            self.__curr.execute(sql)
            for x in self.__curr.fetchall():
                cols.append(x[0])
                pass
        except:
            messagebox.showerror("Error", "Can't fetch column names")
            sys.exit(1)
            pass
        return tuple(cols)

    def __get_data(self):
        data = []
        try:
            sql = "SELECT * FROM `stumanage_students` WHERE 1"
            self.__curr.execute(sql)
            data = [x for x in self.__curr.fetchall()]
        except:
            messagebox.showerror("Error", "Can't fetch data")
            pass
        return data

    pass
