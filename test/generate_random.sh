num_kvp=$1
echo "40"
for (( i=1; i<=$num_kvp; i++ ))
do
    keylen=$(echo $((1 + RANDOM % 20)))
    key=$( head /dev/urandom | tr -dc A-Za-z0-9 | head -c $keylen ; echo '')
    vallen=$(echo $((1 + RANDOM % 20)))
    value=$( head /dev/urandom | tr -dc A-Za-z0-9 | head -c $vallen ; echo '')
    echo $key" "$value
done
