echo "---Fibonocci series---"
echo -n "Enter numer of element : "
read n
a=0
b=1
echo -n "Fibonocci series : $b"
i=2
while [ $i -le $n ]
do
	c=$(($a+$b))
	echo -n " $c"
	a=$b
	b=$c
	i=$(($i+1))
done