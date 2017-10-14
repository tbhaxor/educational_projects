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
        try:
            self.conn = pymysql.connect(self.dbhost, self.dbuser, self.dbpass, self.dbname)
        except:
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - UNABLE TO CONNECT TO DATABASE", colorama.Fore.LIGHTYELLOW_EX, "\n[!] Info - Exiting")
            print(colorama.Style.RESET_ALL)  # resetting colors
            os._exit(1)
            pass

        self.cur = self.conn.cursor()
        pass

    def get(self):
        libs.banner.banner()
        print("<--=[Add New Entry]=-->\n\n")
        self.rollno = str(input("enter roll number : "))
        if not self.is_exists():
            self.name = str(input("enter name : "))
            self.dob = str(input("enter date of birth (dd/mm/yyyy): "))
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
        try:
            sql = "INSERT INTO `stumanage_students`(`roll_no`, `name`, `dob`, `father_name`, `mother_name`, `email`, `contact_number`, `father_c_number`, `mother_c_number`, `nationality`, `address`, `remarks`) VALUES ('{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}')".format(self.rollno, self.name, self.dob, self.fname, self.mname, self.email, self.snum, self.fnum, self.mnum,self.nationality, self.addr, self.rem)
            self.cur.execute(sql)
            self.conn.commit()
            print(colorama.Fore.LIGHTGREEN_EX, "\n[!] Success - New Entry Added")
        except AttributeError:
            self.conn.rollback()
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Roll Number {} doesn't exists".format(self.rollno))
            pass
        except:
            self.conn.rollback()
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Can't Run Query")
            pass
        pass

    def destroy(self):
        self.conn.close()
        pass

    def is_exists(self):
        sql = "SELECT 1 FROM `stumanage_students` WHERE `roll_no`='{}'".format(self.rollno)
        try:
            self.cur.execute(sql)
            data = self.cur.fetchall()
            if len(data) < 1:
                return False
            return True
        except:
            self.conn.rollback()
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Can't Run Query")
            pass
        pass

    pass
