#!/bin/bash

./sortie1
res=$?

if [ $res -eq 0 ]
then
  echo "Valeur comprise entre 5 et 10"
else
  echo "Pas bon"
fi
