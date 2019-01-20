gcc -Wall -Wextra -Werror main.c -o rush-1 || exit 1
./rush-1 1234 3412 4123 2341| cat -e || exit 1
echo
./rush-1 1234 3.12 4123 2.41| cat -e || exit 1
echo
./rush-1 1234 .... 4123 2341| cat -e || exit 1
#./rush-1 1... .2.. ..3. ...4| cat -e || exit 1
#./rush-1 .... .... .... ....| cat -e || exit 1
#./rush-1 1234 2341 3412 4...| cat -e || exit 1
