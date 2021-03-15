#!/usr/bin/gnuplot
set termoption enhanced
set terminal svg size 800,600 font "Arial, 16"
set output "exp1.svg"
set style line 1 lc rgb "0xDC143C" lt 1 lw 4 pt 9 ps 1
set style line 2 lc rgb "0x6495ED" lt 1 lw 4 pt 7 ps 1
set border lw 1
set grid
set key top left
set xlabel "Количество элементов в словаре"
set ylabel "Время выполнения функции, с"
set mxtics
set format x "%6.0f"
set format y "%.6f"
set logscale y 
plot "exp1.txt" using 1:2 title "bstree lookup" with linespoints linestyle 1, \
"exp1.txt" using 1:3 title "hashtab lookup" with linespoints linestyle 2
