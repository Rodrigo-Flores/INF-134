g++ $1 -o program.out -Wall
echo "Continue? (1/0): "
read answer
if [ $answer == 1 ]; then
	./program.out
	rm program.out
fi

echo "Clear screen? (1/0): "
read cscreen
if [ $cscreen == 1 ]; then
	clear
fi
