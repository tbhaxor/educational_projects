#!/bin/bash

echo -e "\t\tEnter The path of Directory\n"
read ND



#Check if the Directory exist of not


if [[ -d "$ND" ]]
then
	while :
	do
	echo -e "\t\t[L]ist the files of current Directory "
	echo -e "\t\t[R]ead a particular file of current Directory "
	echo -e "\t\t[D]elete a file from current Directory "
	echo -e "\t\t[Di]rectory Listing of current Directory "
	echo -e "\t\t[O]pen a Sub Directory "
	echo -e "\t\t[Re]move a Sub Directory "
	echo -e "\t\t[T]erminate"
	read OP
	clear
	case $OP in
		"L"|"l")
			ls -l $ND|grep ^-
			read -n1 kbd
			clear
				;;
		"R"|"r")
			read -p "Enter The name of file " FN
			a=`echo "$FN"|grep "/"`
			FN=`echo "$ND/$FN"`
			if [[ -z "$a" && -f $FN ]]
			then
				cat $FN
			else
				echo -e "File not in the pwd\n"
			fi
			read -n1 kbd
			clear
			;;
		"D"|"d")
			read -p "Enter The name of file " FN
			a=`echo "$FN"|grep "/"`
			FN=`echo "$ND/$FN"`
			if [[ -z "$a" && -f "$FN" ]]
			then
				rm -f $FN
				echo -e "File Deleted \n"
			else
				echo -e "File not in pwd\n"
			fi
			read -n1 kbd
			clear
			;;
		"DI"|"Di"|"dI"|"di")
				ls -l $ND|grep ^d
				read -n1 kbd
				clear
				;;
		"O"|"o")
			read -p "Enter The name of Sub Directory " FN
			a=`echo "$FN"|grep ^/`
			b=`echo "$FN"|cut -d "." -f 2`
			if [[ -z "$a" || "$b" == "/" && -d "$FN" ]]
			then
			ND="$ND/$FN"
				cd "$ND"
			echo -e "Directory Changed pwd is $ND\n"
			else
				echo -e "Directory not in pwd\n"
			fi
			read -n1 kbd
			clear
			;;
		"Re"|"eR"|"RE"|"re")
					
			read -p "Enter The name of Sub Directory " FN
			a=`echo "$FN"|grep ^/`
			b=`echo "$FN"|cut -d "." -f 2`
			if [[ -z "$a" || "$b" == "/" && -d "$FN" ]]
			then
				rm -rf $FN
				echo -e "$FN Deleted\n"
			else
				echo -e "Directory not in pwd\n"
			fi
			read -n1 kbd
			clear
			;;
		"T"|"t")
			break
			;;
		*)
			echo -e "USAGE: Please Select 'L','R','D','DI','O','RE','T'\n"
			read -n1 kbd
			clear
			;;
		esac
done
else
	echo -e "Directory doesnot Exist\n"
fi
