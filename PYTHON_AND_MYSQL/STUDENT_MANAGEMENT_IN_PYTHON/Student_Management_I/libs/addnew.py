# importing local modules
import libs.banner
import libs.config
# importing third party modules
import colorama
import pymysql

# class to add new entry
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

    # method to get all details fromt the user
    def get(self):
        libs.banner.banner()
        print("<--=[Add New Entry]=-->\n\n")
        self.rollno = str(input("enter roll number : "))
        if not self.is_exists(): # checking if roll_number already alloted or not
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

    # method to execute the sql query and commit changes
    def execute(self):
        try:
            sql = "INSERT INTO `stumanage_students`(`roll_no`, `name`, `dob`, `father_name`, `mother_name`, `email`, `contact_number`, `father_c_number`, `mother_c_number`, `nationality`, `address`, `remarks`) VALUES ('{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}','{}')".format(self.rollno, self.name, self.dob, self.fname, self.mname, self.email, self.snum, self.fnum, self.mnum,self.nationality, self.addr, self.rem)
            self.cur.execute(sql) # executing sql connection
            self.conn.commit() # commiting changes
            print(colorama.Fore.LIGHTGREEN_EX, "\n[!] Success - New Entry Added")
        except AttributeError: # error will encountered if roll_number exists
            self.conn.rollback() # rolling back all the changes
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Roll Number {} doesn't exists".format(self.rollno))
            pass
        except:
            self.conn.rollback()  # rolling back all the changes
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Can't Run Query")
            pass
        pass

    # method for closing mysql connection
    def destroy(self):
        self.conn.close()
        pass

    # method for checking if already exists or not
    def is_exists(self):
        sql = "SELECT 1 FROM `stumanage_students` WHERE `roll_no`='{}'".format(self.rollno) # sql to check if columns exists or not
        try:
            self.cur.execute(sql) # executing sql
            data = self.cur.fetchall() # fetching all the db
            if len(data) < 1:
                return False
            return True
        except:
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Can't Run Query")
            pass
        pass
        return None
    pass
