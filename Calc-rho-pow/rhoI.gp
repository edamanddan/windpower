reset session

set xrange[0:358]
set yrange[0.7:0.85]
set grid
set title "Densidad de Aire (Gas ideal) [Kg/m3]"
set xlabel "DIA"
set ylabel "Densidad de Aire [kg/m3]"

plot "promRhoI.txt" u 1:2 w l lt 1 lw 2 title "Densidad de Aire"
