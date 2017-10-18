# importing builtin modules
import pip
import os


def chk():
    try: # trying to import pymysql
        import pymysql
    except (ImportError, ModuleNotFoundError): # on error it will install
        os.system("cls")
        print("[!] Installing Dependency - pymysl")
        pip.main(["install", "pymysql"]) # Installing pymysql
        pass
    try: # trying to import dashtable
        import dashtable
    except (ImportError, ModuleNotFoundError): # on error it will install
        os.system("cls")
        print("[!] Installing Dependency - dashtable")
        pip.main(["install", "dashtable"]) # Installing dashtable
        pass
    try: # trying to import colorama
        import colorama
    except (ImportError, ModuleNotFoundError): # on error it will install
        os.system("cls")
        print("[!] Installing Dependency - colorama")
        pip.main(["install", "colorama"])  # Installing colorama
        pass
    pass
