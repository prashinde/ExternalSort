num_kvp=$1
echo "40" >> ../test.in
for (( i=1; i<=$num_kvp; i++ ))
do
    keylen=$(echo $((1 + RANDOM % 20)))
    key=$( head /dev/urandom | tr -dc A-Za-z0-9 | head -c $keylen ; echo '')
    vallen=$(echo $((1 + RANDOM % 20)))
    value=$( head /dev/urandom | tr -dc A-Za-z0-9 | head -c $vallen ; echo '')
    echo $key" "$value >> ../test.in
done

rm -rf /tmp/final
../ExternalSort < ../test.in

(cat /tmp/final | cut -d' ' -f1) > /tmp/firstCol
cp /tmp/firstCol /tmp/firstColtemp
sort /tmp/firstCol
md5sum /tmp/firstCol
md5sum /tmp/firstColtemp
