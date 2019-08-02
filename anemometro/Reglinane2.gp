reset session

set autoscale
set grid
set title "REGRESIÓN LINEAL mV - rpm"
set xlabel "Voltaje Generado [mV]"
set ylabel "Velocidad de Giro [rpm]"
set key top center box
plot "ane2.dat" using 1:2 w p pt 8 ps 1.5 title "Datos Experimentales"

f(x)=a+b*x

fit f(x) "ane2.dat" using 1:2 via a,b   

replot f(x)