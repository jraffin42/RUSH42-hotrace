# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    convert_ressources.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 15:13:52 by jraffin           #+#    #+#              #
#    Updated: 2021/12/12 17:19:10 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for FILE in $1/*
do
	grep = $FILE | tr '=' '\n' > ./$(basename $FILE)
	echo "" >> ./$(basename $FILE)
	grep -v = $FILE | grep -v ^! >> ./$(basename $FILE)
done
