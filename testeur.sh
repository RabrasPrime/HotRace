#!/bin/bash

# Nombre de tests
NB_TESTS=10

total_time=0

echo "=== Test hotrace ($NB_TESTS runs) ==="

for ((i=1; i<=NB_TESTS; i++))
do
    echo "Run $i..."

    # Mesure du temps avec nanosecondes
    start=$(date +%s.%N)

    ./hotrace < massive_test.htr > /dev/null

    end=$(date +%s.%N)

    # Calcul durée
    duration=$(echo "$end - $start" | bc)

    echo "Temps: $duration s"

    total_time=$(echo "$total_time + $duration" | bc)
done

# Moyenne
average=$(echo "scale=6; $total_time / $NB_TESTS" | bc)

echo "=============================="
echo "Temps total : $total_time s"
echo "Temps moyen : $average s"
echo "=============================="