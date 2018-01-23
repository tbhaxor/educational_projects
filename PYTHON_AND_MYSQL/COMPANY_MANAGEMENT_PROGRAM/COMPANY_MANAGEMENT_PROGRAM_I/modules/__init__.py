# importing all the modules
import modules.config as config
from modules.banner import banner
from modules.add import AddNew
# ----------------------
# 	About the coder info function
# ----------------------
def about():
	banner()     # printing the banner
	print("Coded By :", config.CODER['name'])
	print("Submitted to :", config.CODER['submit_to'])
	print("Institution :", config.CODER['inst'])
	input("\n\n[!] Press Enter to Continue ...")   # pausing the utput screen 
	pass

# ----------------------
#	Prints the menu
# ----------------------
def menu():
	banner()
	print("<--[ MENU ]-->")
	print("1. Add New")
	print("2. Delete Existing")
	print("3. Search Entry")
	print("4. Show All")
	print("5. Exit")
	pass

# ----------------------
#	Driving function
# ----------------------
def main():
	while(True):
		try: # trying to parse the 
			menu()  # printing the menu
			opt = int(input("> "))
		except ValueError:  # on non-integer value prints error message
			print("[!] Only integers are accepted")
			input("[!] Press Enter to Continue ...")
			continue
		if opt == 5:
			break
		elif opt == 1:
			obj = AddNew() # creating an instance of the class AddNew in add module
			obj.mainloop() # invoking mainloop method of class AddNew
			pass
		elif opt == 2:
			pass
		elif opt == 3:
			pass
		elif opt == 4:
			pass
		else:
			print("[x] Invalid input")
			input("[!] Press Enter to Continue ...")
		pass
	pass