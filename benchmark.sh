# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 17:57:13 by jraffin           #+#    #+#              #
#    Updated: 2021/12/13 01:19:40 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make re

for i in {1..10}
do
	echo "-> timing on generated-$i"
	/usr/bin/time hotrace < ressources/generated-$i > /dev/null
done

