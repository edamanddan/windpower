reset session

set xrange[0:358]
#set yrange[0:1]
set grid
set title "Intensidad Eólica extrapolación 20m (Aire Húmedo) [W/m2]"
set xlabel "DIA"
set ylabel "Intensidad de viento [W/m2]"

plot "promI20dh.txt" u 1:2 w l lt 8 lw 2 title "Intensidad de Viento"
