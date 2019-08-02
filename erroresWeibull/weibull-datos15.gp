reset

#set style data histogram
#set style histogram cluster gap 1
set style fill solid border -1
set xrange[:17]
set yrange[0:0.3]
#set boxwidth 1.5
set grid
set title "BARRAS DE ERROR \n {/*0.9 DATOS EXPERIMENTALES - DISTRIBUCIÓN DE WEIBULL (15m)}" 
set xtic rotate by -45
set bmargin 5
set xlabel "Velocidad de Viento (m/s)"
set ylabel "Frecuencia (Función de Distribución)"

plot "errorweibull15.txt" u 3:5 w yerrorbars lt 4 lw 2 title "Barras de Error" 

set xrange[-0.3:18]
set yrange[0:0.3]
#set xlabel "Velocidad de Viento"
#set ylabel "Función de Distribución"
#set title "DISTRIBUCIÓN AJUSTADA DE WEIBULL"

k=1.1955844
C=3.4608772

F(x)=(k/C)*((x/C)**(k-1))*exp(-(x/C)**k)

replot F(x) w l lt 0 lw 2 title "(Ajuste Weibull)"
