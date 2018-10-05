#!/bin/bash

# sudo user check
if [[ "$EUID" -ne 0 ]]; then
	echo "Run it with root privileges!!"
	exit 1
fi



#function to test errors

function test(){
pkill yum
a=`ping 8.8.8.8 -w 1 -c 1 | grep ttl`
if [[ -z $a ]]
then
echo  -e "Network Error\n"
echo -e "\033[1;31m Network Error\033[2;30m\n"
else
echo -e "\033[1;31m Error Occured Read logs at ~/log\033[2;30m\n"
fi
exit 0
}

echo -e "\033[1;31m YUM LOGS\033[2;30m" > ~/log
yum install httpd -y >> ~/log 2> /dev/null
read -p "Enter Index File Path " PT
echo -e "\033[1;31m FIREWALL LOGS\033[2;30m" >> ~/log
firewall-cmd --permanent --add-service=http 2>> ~/log >> /dev/null
firewall-cmd --reload >> /dev/null
echo -e "\033[1;31m 'cp' command LOGS\033[2;30m" >> ~/log
cp $PT /var/www/html 2>> ~/log
echo -e "\033[1;31m 'systemctl' command LOGS\033[2;30m" >> ~/log
systemctl start httpd 2>> ~/log 
(( $# !=0 )) && test
systemctl enable httpd 2>> ~/log

