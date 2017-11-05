# importing third party modules
import dashtable
import pymysql
import colorama
# importing local modules
import libs.config
import libs.banner

# class to search an entry and display its details
class search():
    def __init__(self):
        self.dbhost = libs.config.dbhost
        self.dbname = libs.config.dbname
        self.dbuser = libs.config.dbuser
        self.dbpass = libs.config.dbpass
        try:
            self.conn = pymysql.connect(self.dbhost, self.dbuser, self.dbpass, self.dbname)
        except:
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - UNABLE TO CONNECT TO DATABASE",
                  colorama.Fore.LIGHTYELLOW_EX, "\n[!] Info - Exiting")
            print(colorama.Style.RESET_ALL)  # resetting colors
            os._exit(1)
            pass

        self.cur = self.conn.cursor()
        pass

    # getting roll_number to be printed
    def get(self):
        libs.banner.banner()
        print("<--=[Search Entry]=-->\n\n")
        self.roll_number = input("enter roll number you want to search : ")
        pass

    # method to print the data
    def view(self):
        libs.banner.banner()
        print("<--=[Viewing for {}]=-->\n\n".format(self.roll_number))
        data = self.execute() # getiing data from sql
        if len(data) > 1: # checking if roll number exists or not
            print(dashtable.data2rst(data, center_cells=True))
            print(colorama.Fore.LIGHTGREEN_EX + "\n[!] Success - Successfully executed")
            pass
        else:
            print(colorama.Fore.LIGHTRED_EX + "\n[x] Error - Roll number {} doesn't exists".format(self.roll_number))
            pass
        pass

    # method to execute the return the data
    def execute(self):
        try:
            data = []
            sql1 = "SELECT column_name FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME='stumanage_students' "
            sql2 = "SELECT * FROM `stumanage_students` WHERE `roll_no`='{}'".format(self.roll_number) # sql for getting roll number details
            self.cur.execute(sql1) # executing for columns
            a = [x[0] for x in self.cur.fetchall()]
            data.append(a)
            self.cur.execute(sql2) # executing for details
            for x in self.cur.fetchall():
                data.append(list(x))
                pass
            return data # returning tuple
        except:
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Can't Run Query")
            pass
        pass

    # closing mysql connection
    def destroy(self):
        self.conn.close()
        pass
    pass
