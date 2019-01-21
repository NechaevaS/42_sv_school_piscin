gcc -Wall -Wextra -Werror main.c board_utilits.c check_param.c solve.c -o rush-1 || exit 1
#./rush-1 1234 3412 4123 2341| cat -e || exit 1
#echo
#./rush-1 1234 3.12 4123 2.41| cat -e || exit 1
#cho
#./rush-1 1234 .... 4123 2341| cat -e || exit 1
#./rush-1 1... .2.. ..3. ...4| cat -e || exit 1
#./rush-1 .... .... .... ....| cat -e || exit 1
./rush-1 9...7.... 2...9..53 .6..124.. 84...1.9. 5.....8.. .31..4... ..37..68. .9..5.741 47.......| cat -e || exit1
