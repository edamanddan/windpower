reset
set style data dots
set autoscale
set grid
set xtic auto
set ytic auto
set xlabel "Velocidad de Viento (m/s)"

set key top center box
set ylabel "Intensidad (W/m2)"
    
set title "Relación Intensidad-Velocidad de Viento para altura Z=25m (Densidad aire húmedo)"


plot "Ih25.txt" u 1:3 title '   Datos  ' w p pt 8 ps 1

f(x)=a*(x**b)

fit f(x) "Ih25.txt" u 1:3 via a,b 

replot f(x)
