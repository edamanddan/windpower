reset
set style data dots
set autoscale
set grid
set xtic auto
set ytic auto
set xlabel "Ln(v)"

set key top center box
set ylabel "Ln(-Ln(1-F(v)))"
    
set title "Linealización para determinar los parámetros C y K de la distribución de Weibull con Z=15m"


plot "w15.txt" u 1:2 title '   Datos  ' w p pt 2 ps 2

f(x)=a+b*x

fit f(x) "w15.txt" u 1:2 via a,b 

replot f(x)
