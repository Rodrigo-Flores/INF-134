g++ $1 -o program.out -Wall
echo "Continue? (1/0): "
read answer
if [ $answer == 1 ]; then
	echo "Output:"
	echo ""
	./program.out
	rm program.out
	echo ""
	echo "End of the program..."
	echo "Clear screen? (1/0): "
	read cscreen
	if [ $cscreen == 1 ]; then
		clear
	fi
fi
