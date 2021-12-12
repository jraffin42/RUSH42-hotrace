# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    diff.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 22:59:30 by jraffin           #+#    #+#              #
#    Updated: 2021/12/12 23:12:56 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for i in {1..10}
do
	echo "diff for generated-$i :"
	diff output/cclaude-$i.txt output/jraffin-$i.txt
done
