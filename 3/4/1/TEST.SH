#!/bin/sh

namescript=$1
for file in *;
do
    echo "mv $file $(echo $file | tr '[:lower:]' '[:upper:]')" >> "$namescript"
done

$(chmod +x $namescript)
