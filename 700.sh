ARG=`jot -r 100 -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`

while [ $NUM -lt 700 ]
do
ARG=`jot -r 100 -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
echo $NUM
#echo `./push_swap $ARG | ./checker_Mac $ARG`
done
