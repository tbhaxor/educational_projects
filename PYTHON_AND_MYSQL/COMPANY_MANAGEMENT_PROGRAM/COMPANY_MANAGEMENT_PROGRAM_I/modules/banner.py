import os

def banner():
	if os.system("cls") != 0:
		os.system("clear")
	
	print("""
 ________________________________________
|                                        |
|                                        |
|       COMPANY MANAGEMENT PROGRAM       |
|                                        |
|________________________________________|
		""")