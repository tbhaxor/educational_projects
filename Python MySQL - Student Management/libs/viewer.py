import colorama
import libs.banner
import libs.config
import pymysql
import os
import dashtable

class viewer():
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

    def view(self):
        libs.banner.banner()
        print("<--=[Viewing All]=-->\n")
        data = self.execute()
        rows = len(data) - 1
        if rows > 0:
            print(colorama.Fore.LIGHTGREEN_EX + "[*] Success - Total ", rows, "row(s) fetched\n\n" + colorama.Style.RESET_ALL)
            print(dashtable.data2rst(data, use_headers=True, center_cells=True))
        else:
            print(colorama.Fore.LIGHTBLUE_EX + "[*] Info - No Entry Found" + colorama.Style.RESET_ALL)
        pass

    def execute(self):
        data = []
        sql1 = "SELECT column_name FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME='stumanage_students' "
        sql2 = "SELECT * FROM `stumanage_students` WHERE 1"
        self.cur.execute(sql1)
        a = [x[0] for x in self.cur.fetchall()]
        data.append(a)
        self.cur.execute(sql2)
        for x in self.cur.fetchall():
            data.append(list(x))
            pass
        return data
        pass

    def destroy(self):
        self.conn.close()
        pass

    pass
