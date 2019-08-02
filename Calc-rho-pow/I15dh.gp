reset session

set xrange[0:358]
#set yrange[0:1]
set grid
set title "Intensidad Eólica extrapolación  15m (Aire húmedo) [W/m2]"
set xlabel "DIA"
set ylabel "Intensidad de viento [W/m2]"

plot "promI15dh.txt" u 1:2 w l lt 6 lw 2 title "Intensidad de Viento"
