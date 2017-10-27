# importing libraries
from libs import dependency, loginportal


if __name__ == '__main__':
    dependency.chk()  # checking dependencies
    a = loginportal.Portal()   # creating object
    a.makepanel()              # making panel
    a.deploy()                 # deploying panel
