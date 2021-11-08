a=10
b=20
echo "Before swap a=$a and b=$b"
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo "After  swap a=$a and b=$b"
