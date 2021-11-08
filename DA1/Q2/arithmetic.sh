echo "--------Arithmetic Operations--------"
echo "a for Addition"
echo "s for Subtraction"
echo "m for Multipliction"
echo "d for Division"
echo -n "Enter your choice : "
read ch
echo "Enter Operants : "
read a
read b
case "$ch" in
	"a")
		echo "$a + $b = $(($a+$b))"
		;;
	"s")
		echo "$a - $b = $(($a-$b))"
		;;
	"m")
		echo "$a * $b = $(($a*$b))"
		;;
	"d")
		echo "$a / $b = $(($a/$b))"
		;;
esac
