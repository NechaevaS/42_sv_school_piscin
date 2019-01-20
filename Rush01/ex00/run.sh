gcc -Wall -Wextra -Werror main.c -o rush-1 || exit 1
#./rush-1 1234 3412 4123 2341| cat -e || exit 1
#./rush-1 1... .2.. ..3. ...4| cat -e || exit 1
./rush-1 .... .... .... ....| cat -e || exit 1
