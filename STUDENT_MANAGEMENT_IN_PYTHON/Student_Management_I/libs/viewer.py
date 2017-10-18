# importing third party modules
import pymysql
import colorama
import dashtable
# importing local modules
import libs.banner
import libs.config
# importing builtin module
import os


# class viewer to print the data
class viewer():
    # constructor of class to connect to database on object declaration
    def __init__(self):
        # making config
        self.dbhost = libs.config.dbhost
        self.dbname = libs.config.dbname
        self.dbuser = libs.config.dbuser
        self.dbpass = libs.config.dbpass
        try: # trying to connect to database
            self.conn = pymysql.connect(self.dbhost, self.dbuser, self.dbpass, self.dbname) # database is connected and object of connection is made
        except: # to catch if error is encountered while connecting to the database
            print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - UNABLE TO CONNECT TO DATABASE",
                  colorama.Fore.LIGHTYELLOW_EX, "\n[!] Info - Exiting")
            print(colorama.Style.RESET_ALL)  # resetting colors
            os._exit(1) # Exiting with Error on error while connecting to db
            pass

        self.cur = self.conn.cursor() # making an variable for cursor
        pass

    # method to view all the details
    def view(self):
        libs.banner.banner() # printing the banner
        print("<--=[Viewing All]=-->\n")
        data = self.execute() # execute and getting data
        rows = len(data) - 1
        if rows > 0:  # checks if table has any data or not
            print(colorama.Fore.LIGHTGREEN_EX + "[*] Success - Total ", rows,
                  "row(s) fetched\n\n" + colorama.Style.RESET_ALL)
            print(dashtable.data2rst(data, center_cells=True, use_headers=True))
        else:
            print(colorama.Fore.LIGHTBLUE_EX + "[*] Info - No Entry Found" + colorama.Style.RESET_ALL)
        pass

    # executing sql
    def execute(self):
        data = []
        sql1 = "SELECT column_name FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME='stumanage_students' "  # sql statement to get column_name
        sql2 = "SELECT * FROM `stumanage_students` WHERE 1" # sql statement to fetch all data
        self.cur.execute(sql1)   # executing query
        a = [x[0] for x in self.cur.fetchall()]  # fetching all column_names
        data.append(a) # loading column_names in data
        self.cur.execute(sql2)  # executing for student data
        for x in self.cur.fetchall():
            data.append(list(x)) # appending in
            pass
        return data  # returning sql data
        pass

    # method to close the connection
    def destroy(self):
        self.conn.close()
        pass

    pass
