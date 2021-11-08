echo -n "Enter Mark of Student : "
read mark
echo -n "Student grade is : "
if [ $mark -ge 90 ]
then
	echo "S"
elif [ $mark -ge 80 ]
then
	echo "A"
elif [ $mark -ge 70 ]
then
	echo "B"
elif [ $mark -ge 60 ]
then
	echo "C"
elif [ $mark -ge 55 ]
then
	echo "D"
elif [ $mark -ge 50 ]
then
	echo "E"
else
	echo "F"
fi
