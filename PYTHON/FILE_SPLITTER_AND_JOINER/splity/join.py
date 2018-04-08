import glob
import os
import splity.config as c
from colorama import Fore, Style

def main(file, k):
    parts = sorted(glob.glob(os.path.join(os.getcwd(), "*.{0}".format(c.SPLIT_EXT))))
    f_new = open(file, "w")
    print("{0}[*]{1} {2}Joining *.{3} to '{4}'{5}".format(Fore.LIGHTBLUE_EX, Style.RESET_ALL, Fore.LIGHTYELLOW_EX, c.SPLIT_EXT, file, Style.RESET_ALL))
    for part in parts:
        with open(part, "r") as f:
            f_new.write(f.read())
            f.close()
        
        if not k:
            os.unlink(part)
    f_new.close()
    print("{0}[!]{1} {2}Joining Done !!!{3}".format(Fore.LIGHTGREEN_EX, Style.RESET_ALL, Fore.LIGHTYELLOW_EX, Style.RESET_ALL))
    pass