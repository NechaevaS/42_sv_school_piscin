EXP=./eval_expr
REF=bc

TESTS=(
	' 2 + 3 '
	' 2 + 3 * 5 '
	'2 * 3 + 5'
	'(-5)'
	'-5 + 3'
	'5 + -3'
	' ( ( ( ( 6 ))) )'
	' ( 3*( ( ( 6  + 5))+2) )'
	' ( 2 + ( 3 + 4 )*( 6 + 5 ) - 6 / (4 - 2)) '
)

for test in "${TESTS[@]}"; do 
	ERES=$($EXP "$test")
	RRES=$(echo "$test" | $REF)
	
	echo -n "$test: "

	if [ "$ERES" = "$RRES" ]; then
		echo -n "PASSED"
	else
		echo -n "FAILED"
	fi

	echo " - EXPECTED($RRES), RESULT($ERES)"
done
		
