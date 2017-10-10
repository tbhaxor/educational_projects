# importing local dependencies
import libs.dependency
import libs.banner
import libs.addnew
# importing global / inbuilt libs
import os
import colorama


def menu():
    libs.banner.banner()
    print("<--=[Menu]=-->", end="\n\n")
    print(colorama.Fore.RED, "[1]", colorama.Fore.YELLOW, " Add New Entry")
    print(colorama.Fore.RED, "[2]", colorama.Fore.YELLOW, " Delete Entry")
    print(colorama.Fore.RED, "[3]", colorama.Fore.YELLOW, " List All")
    print(colorama.Fore.RED, "[4]", colorama.Fore.YELLOW, " Search Entry")
    print(colorama.Fore.RED, "[5]", colorama.Fore.YELLOW, " Modify Entry")
    print(colorama.Fore.RED, "[6]", colorama.Fore.YELLOW, " Exit", colorama.Style.RESET_ALL)
    return int(input(" > "))
    pass


def loop():
    while True:
        opt = menu()
        if opt == 6:
            os._exit(0)
            pass
        elif opt == 1:
            a = libs.addnew.addNew()
            a.get()
            a.execute()
            a.destroy()
            pass
        elif opt == 2:
            pass
        elif opt == 3:

            pass
        elif opt == 4:
            pass
        elif opt == 5:
            pass

        input(colorama.Fore.LIGHTYELLOW_EX + "\n\n[!] Info - Press Enter To Continue" + colorama.Style.RESET_ALL)
    pass


if __name__ == '__main__':
    libs.dependency.chk()
    try:
        loop()
    except KeyboardInterrupt:
        print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - USER INTERRUPT", colorama.Fore.LIGHTYELLOW_EX,"\n[!] Info - Exiting")
        print(colorama.Style.RESET_ALL)  # resetting colors
        os._exit(1)
        pass
    except ValueError:
        print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - VALUE EXCEPT INTEGERS WERE ENTERED", colorama.Fore.LIGHTYELLOW_EX,"\n[!] Info - Exiting")
        print(colorama.Style.RESET_ALL)  # resetting colors
        os._exit(1)
        pass
    print(colorama.Style.RESET_ALL)  # resetting colors
    pass
