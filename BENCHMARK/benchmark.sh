# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 17:57:13 by jraffin           #+#    #+#              #
#    Updated: 2021/12/12 18:41:43 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make -C cclaude re
make -C .. re


for i in {1..10}
do
	echo "-> timing jraffin on generated-$i"
	/usr/bin/time -f 't += ( %U + %S )' -ao ./timings/jraffin.txt ../hotrace < ../ressources/generated-$i > ./output/jraffin-$i.txt
	echo "-> timing cclaude on generated-$i"
	/usr/bin/time -f 't += ( %U + %S )' -ao ./timings/cclaude.txt cclaude/hotrace < ./old_modified_ressources/generated-$i > ./output/cclaude-$i.txt
done

for i in {1..10}
do
	echo "diff for generated-$i :"
	diff output/cclaude-$i.txt output/jraffin-$i.txt
done

rm ./timings/ALL.txt &> /dev/null

for user in cclaude jraffin
do
	echo "print t" >> ./timings/${user}.txt
	echo "quit" >> ./timings/${user}.txt
	echo "$(bc -q ./timings/${user}.txt) seconds : $user" >> ./timings/ALL.txt 2> /dev/null
done
