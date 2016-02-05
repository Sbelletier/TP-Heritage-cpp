#TEST 1
#LIST sur modele vide
echo "test n°1"
../B3122_TP_Heritage.out <In1.txt >Out1.txt
diff -wB Out1.txt Exp1.txt
if [ $? -eq 0 ]
        then
		echo "test n°1 PASSED"

	else
		echo "test n°1 FAILED"
fi

#TEST 2
#Tests autour de Segment
echo "test n°2"
../B3122_TP_Heritage.out <In2.txt >Out2.txt
diff -wB Out2.txt Exp2.txt
if [ $? -eq 0 ]
        then
		echo "test n°2 PASSED"

	else
		echo "test n°2 FAILED"
fi

#TEST 3
#Tests autour de Rectangle
echo "test n°3"
../B3122_TP_Heritage.out <In3.txt >Out3.txt
diff -wB Out3.txt Exp3.txt
if [ $? -eq 0 ]
        then
		echo "test n°3 PASSED"

	else
		echo "test n°3 FAILED"
fi

#TEST 4
#Tests autour de Polygon
echo "test n°4"
../B3122_TP_Heritage.out <In4.txt >Out4.txt
diff -wB Out4.txt Exp4.txt
if [ $? -eq 0 ]
        then
		echo "test n°4 PASSED"

	else
		echo "test n°4 FAILED"
fi

#TEST 5
#Tests Union simple
echo "test n°5"
../B3122_TP_Heritage.out <In5.txt >Out5.txt
diff -wB Out5.txt Exp5.txt
if [ $? -eq 0 ]
        then
		echo "test n°5 PASSED"

	else
		echo "test n°5 FAILED"
fi

#TEST 6
#Test Union d union
echo "test n°6"
../B3122_TP_Heritage.out <In6.txt >Out6.txt
diff -wB Out6.txt Exp6.txt
if [ $? -eq 0 ]
        then
		echo "test n°6 PASSED"

	else
		echo "test n°6 FAILED"
fi

#TEST 7
#Test Intersection simple
echo "test n°7"
../B3122_TP_Heritage.out <In7.txt >Out7.txt
diff -wB Out7.txt Exp7.txt
if [ $? -eq 0 ]
        then
		echo "test n°7 PASSED"

	else
		echo "test n°7 FAILED"
fi

#TEST 8
#Test Intersection d'union
echo "test n°8"
../B3122_TP_Heritage.out <In8.txt >Out8.txt
diff -wB Out8.txt Exp8.txt
if [ $? -eq 0 ]
        then
		echo "test n°8 PASSED"

	else
		echo "test n°8 FAILED"
fi


#TEST 9
#Test UNDO/REDO
echo "test n°9"
../B3122_TP_Heritage.out <In9.txt >Out9.txt
diff -wB Out9.txt Exp9.txt
if [ $? -eq 0 ]
        then
		echo "test n°9 PASSED"

	else
		echo "test n°9 FAILED"
fi

#TEST 10
#Test SAVE/LOAD
echo "test n°10"
../B3122_TP_Heritage.out <In10.txt >Out10.txt
diff -wB Out10.txt Exp10.txt
if [ $? -eq 0 ]
        then	
		diff -wB savt10.txt exp_savt10.txt
		if [ $? -eq 0 ]
			then
				echo "test n°10 PASSED"
			else
				echo "test n°10 FAILED"
			fi

	else
		echo "test n°10 FAILED"
fi





