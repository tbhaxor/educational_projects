# importing functions
from modules import main, about
from sys import exit

if __name__ == '__main__':
	about() # invoking about the coder function
	try:  # trying to run main function
		main()  # invoking main function
	except KeyboardInterrupt: # exits with status code 1 if CTRL + C is pressed
		print("\n[!] User interrupt")