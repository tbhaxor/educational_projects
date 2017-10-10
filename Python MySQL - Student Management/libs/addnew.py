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
        print("<---==[Add New Entry]==--->")
        rollno = str(input("enter roll number : "))
        pass

    def destroy(self):
        self.conn.close()
        pass

    pass
