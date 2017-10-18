# importing local dependencies
import libs.dependency
import libs.banner
import libs.addnew
import libs.viewer
import libs.delete
import libs.search

# importing global / inbuilt libs
import os

# colorama module doesn't come with python it has to be downloaded
libs.dependency.chk()  # chk() method of module dependency checks and install dependency

# importing third party module(s)
import colorama

# function used to print menu
def menu():
    libs.banner.banner()
    print("<--=[Menu]=-->", end="\n\n")
    print(colorama.Fore.RED, "[1]", colorama.Fore.YELLOW, " Add New Entry")
    print(colorama.Fore.RED, "[2]", colorama.Fore.YELLOW, " Delete Entry")
    print(colorama.Fore.RED, "[3]", colorama.Fore.YELLOW, " List All")
    print(colorama.Fore.RED, "[4]", colorama.Fore.YELLOW, " Search Entry")
    print(colorama.Fore.RED, "[5]", colorama.Fore.YELLOW, " Exit", colorama.Style.RESET_ALL)
    return int(input(" > ")) # getting and returning the input
    pass


# function loop excetues the modules untill exit option is not selectes
def loop():
    while True:
        opt = menu()
        # switching the modules
        if opt == 5:
            os._exit(0)  # if 5th option is selected Exiting program with status code of success
            pass
        elif opt == 1:
            a = libs.addnew.addNew()
            a.get()
            a.execute()
            a.destroy()
            pass
        elif opt == 2:
            a = libs.delete.delete()
            a.get()
            ip = input(colorama.Fore.LIGHTCYAN_EX + "Are you sure [y/N]? ")
            if ip.lower() == "y":
                if a.is_exists():
                    a.execute()
                else:
                    print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - Roll Number {} doesn't exists".format(a.roll_numbr))
            a.destroy()
            pass
        elif opt == 3:
            a = libs.viewer.viewer()
            a.view()
            a.destroy()
            pass
        elif opt == 4:
            a = libs.search.search()
            a.get()
            a.view()
            a.destroy()
            pass

        input(colorama.Fore.LIGHTYELLOW_EX + "\n\n[!] Info - Press Enter To Continue" + colorama.Style.RESET_ALL)
    pass


if __name__ == '__main__':  # checks whether same file is being for some other file is calling
    libs.dependency.chk() # checks dependency again
    try:
        loop()
    except KeyboardInterrupt:
        # executes when CTRL - C is pressed
        print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - USER INTERRUPT", colorama.Fore.LIGHTYELLOW_EX,"\n[!] Info - Exiting")
        print(colorama.Style.RESET_ALL)  # resetting colors
        os._exit(1) # Exiting with error
        pass
    except ValueError:
        # executes when any non integer is pressed
        print(colorama.Fore.LIGHTRED_EX, "\n[x] Error - VALUE EXCEPT INTEGERS WERE ENTERED", colorama.Fore.LIGHTYELLOW_EX,"\n[!] Info - Exiting")
        print(colorama.Style.RESET_ALL)  # resetting colors
        os._exit(1)
        pass
    print(colorama.Style.RESET_ALL)  # resetting colors
    pass
