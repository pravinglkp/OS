echo "---Sum of First N natural numbers---"
echo -n "Enter n : "
read n
sum=0
i=1
while [ $i -le $n ]
do
	sum=$(($sum+$i))
	i=$(($i+1))
done
echo "Sum of first $n natural numbers = $sum"
