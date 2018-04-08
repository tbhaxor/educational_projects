from __future__ import division
import os
import splity.config as c
from colorama import Fore, Style
from pbars import ProgressBar

def count(file, c_size):
    s = os.path.getsize(file)
    t = s // c_size
    if s % c_size != 0:
        return t + 1
    return t


def main(file, c_size, keep, o):
    if not os.path.exists(o):
        os.mkdir(o)
    global content
    content = None
    try:
        with open(file, "rb") as f:
            content = f.read().decode()
            f.close()
            pass
    except FileNotFoundError:
        print("{0}[x]{1} {2}File '{file}', Not Found...{3}".format(
            Fore.RED, Style.RESET_ALL, Fore.CYAN, Style.RESET_ALL, file=file))
        os._exit(1)
    filesize = os.path.getsize(file) # getting file size
    base_name = file.split(".")[0]
    l = 0
    total = count(file, c_size)
    print("{0}[*]{1} {2}Started Spliting '{3}'{4}".format(Fore.LIGHTBLUE_EX, Style.RESET_ALL, Fore.LIGHTYELLOW_EX, file, Style.RESET_ALL))
    for i in range(0, filesize, c_size):
        l += 1
        f = "{0}.{1}.{2}".format(base_name, l, c.SPLIT_EXT)
        data = content[i:i + c_size]
        with open(os.path.join(o, f), "wb") as x:
            x.write(data.encode())
            x.close()
            pass
        pass
    print("{0}[!]{1} {2}Spliting Done !!!{3}".format(Fore.LIGHTGREEN_EX, Style.RESET_ALL, Fore.LIGHTYELLOW_EX, Style.RESET_ALL))
    print("{0}[!]{1} {2}Chunks Formed = {c}{3}".format(Fore.LIGHTGREEN_EX, Style.RESET_ALL, Fore.LIGHTYELLOW_EX, Style.RESET_ALL, c=l))
    if not keep:
        os.unlink(file)
    pass