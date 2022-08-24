#!/bin/sh
g++ $1 -o program.out
echo "Continue? (y/n) > "
read answer
if [ "$answer" = "y" ]; then
    clear
    ./program.out
    rm program.out
else
    echo "Exiting..."
fi
