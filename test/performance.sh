num_rounds=$1
num_exp=$2

num_kvp=1
rm -rf plot
for (( k=1; k<$num_rounds; k++ ))
do
    num_kvp=$(( num_kvp*2 ))
    for (( j=0; j<$num_exp; j++ ))
    do
        if [ ! -f ../test.in_$num_kvp ]; then
            echo "80" >> ../test.in_$num_kvp
            for (( i=1; i<=$num_kvp; i++ ))
            do
                keylen=$(echo $((1 + RANDOM % 20)))
                key=$( head /dev/urandom | tr -dc A-Za-z0-9 | head -c $keylen ; echo '')
                vallen=$(echo $((1 + RANDOM % 20)))
                value=$( head /dev/urandom | tr -dc A-Za-z0-9 | head -c $vallen ; echo '')
                echo $key" "$value >> ../test.in_$num_kvp
            done
        fi
        rm -rf /tmp/final
        #Time here
        echo "Number of KVP are:" $num_kvp
        time=$( TIMEFORMAT="%R"; { time ../ExternalSort < ../test.in_$num_kvp; } 2>&1 )
        #time ../ExternalSort < ../test.in_$num_kvp
        echo $time $num_kvp >> plot
    done
done
