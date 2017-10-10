import pip
import os


def chk():
    try:
        import pymysql
    except (ImportError, ModuleNotFoundError):
        os.system("cls")
        print("[!] Installing Dependency - pymysl")
        pip.main(["install", "pymysql"])
        pass
    try:
        import dashtable
    except (ImportError, ModuleNotFoundError):
        os.system("cls")
        print("[!] Installing Dependency - dashtable")
        pip.main(["install", "dashtable"])
        pass
    pass
