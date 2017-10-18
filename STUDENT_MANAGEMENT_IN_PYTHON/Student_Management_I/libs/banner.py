# importing builtin module(s)
import os
# importing third party module
import colorama

# function to print banner
def banner():
    os.system("cls")
    print(colorama.Fore.BLACK, colorama.Back.LIGHTCYAN_EX)
    print("\t\t\t##########################################")
    print("\t\t\t##                                      ##")
    print("\t\t\t##     Student Management Program       ##")
    print("\t\t\t##                                      ##")
    print("\t\t\t##   Coded By     :  Gurkirat Singh     ##")
    print("\t\t\t##   Institution  :  MDU                ##")
    print("\t\t\t##   Submitted To :  Mr. Puneet         ##")
    print("\t\t\t##########################################\n\n")
    print(colorama.Style.RESET_ALL)
    pass
