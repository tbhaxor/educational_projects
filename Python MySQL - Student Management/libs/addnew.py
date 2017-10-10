import libs.banner
import colorama
import libs.config
import pymysql


class addNew():
    def __init__(self):
        self.dbhost = libs.config.dbhost
        self.dbname = libs.config.dbname
        self.dbuser = libs.config.dbuser
        self.dbpass = libs.config.dbpass
        self.conn = pymysql.connect(self.dbhost, self.dbuser, self.dbpass, self.dbname)
        self.cur = self.conn.cursor()
        pass

    def get(self):
        libs.banner.banner()
        print("<---==[Add New Entry]==--->\n\n")
        self.rollno = str(input("enter roll number : "))
        self.name = str(input("enter name : "))
        self.dob = str(input("enter date of birth (dd-mm-yyyy): "))
        self.snum = str(input("enter student's contact number : "))
        self.email = str(input("enter a working email address : "))
        self.fname = str(input("enter father's name : "))
        self.fnum = str(input("enter father's contact number : "))
        self.mname = str(input("enter mother's name : "))
        self.mnum = str(input("enter mother's contact numbers : "))
        self.nationality = str(input("enter nationality (press enter if INDIAN): "))
        if self.nationality == "":
            self.nationality = "indian"
            pass
        self.addr = str(input("enter address : "))
        self.rem = str(input("enter remarks (optional) : "))
        pass

    def execute(self):
        sql = 
        pass

    def commit(self):
        pass

    def destroy(self):
        self.conn.close()
        pass

    pass
