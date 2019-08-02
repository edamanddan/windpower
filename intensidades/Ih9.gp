reset
set style data dots
set autoscale
set grid
set xtic auto
set ytic auto
set xlabel "Velocidad de Viento (m/s)"

set key top center box
set ylabel "Intensidad (W/m2)"
    
set title "Relación Intensidad-Velocidad de Viento para altura base 9m (Densidad de aire humedo)"


plot "Ih9.txt" u 1:3 title '   Datos  ' w p pt 1 ps 2

f(x)=a*(x**b)

fit f(x) "Ih9.txt" u 1:3 via a,b 

replot f(x)
