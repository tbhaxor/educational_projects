# importing built in modules
import pip
import sys
import os


# function to check and install dependencies
def chk():
    # trying to import the pymysql module
    try:
        import pymysql
    except (ImportError, ModuleNotFoundError):  # lines under exception will be executed if module pymysql is not found
        os.system("cls")                                          # clearing screen
        print("[!] Installing Dependency - pymysl")               # printing message
        pip.main(["install", "pymysql"])                          # installing the dependencies
        print("[!] Info - Dependencies have been installed")      # printing info
        print("[!] Info - Exiting Program")                       # printing info
        sys.exit(1)                                               # exiting the program
        pass
    pass
