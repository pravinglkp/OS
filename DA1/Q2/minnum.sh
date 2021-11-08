echo -n "enter a : "
read a
echo -n "enter b : "
read b
echo -n "enter c : "
read c
if [ $a -lt $b -a $a -lt $c ] 
then
	echo "$a is smaller than $b and $c"
elif [ $b -lt $c ]
then
	echo "$b is smaller than $a and $c"
else
	echo "$c is smaller than $a and $b"
fi