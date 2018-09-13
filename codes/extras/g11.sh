#!/bin/bash

IFS=''
g++ -std=c++11 -o $1.out ./$1/$1.cpp
for i in {1..2};
do
	echo "Teste $i"
	./$1.out < $1/input/in$i > $1/output/saida$1
	Diff=$(diff $1/output/saida$1 $1/output/out$i)
	if [ "$Diff" ]; then
		echo "$Diff"
	else
		echo "Ok"
	fi
done

read -s -N 1 -p "Submit problem $1?[s/n] " option
if  [[ "$option" == "S" ]] || [[ "$option" == "s" ]] || [[ "$option" == $'\x0a' ]] ; then
	echo "submit" $1;
	# adicionar comando de submissao
else
	echo "done"
fi
