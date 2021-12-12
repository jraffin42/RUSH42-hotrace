# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 17:57:13 by jraffin           #+#    #+#              #
#    Updated: 2021/12/12 23:13:43 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make -C cclaude re
make -C .. re


for i in {1..10}
do
	echo "-> timing cclaude on generated-$i"
	/usr/bin/time cclaude/hotrace < old_modified_ressources/generated-$i > ./output/cclaude-$i.txt
	echo "-> timing jraffin on generated-$i"
	/usr/bin/time ../hotrace < ../ressources/generated-$i > ./output/jraffin-$i.txt
done
