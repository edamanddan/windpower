reset

#set style data histogram
#set style histogram cluster gap 1
set style fill solid border -1
set xrange[:17]
set yrange[0:]
#set boxwidth 1.5
set grid
set title "Comparación Distribuciones Weibull para diferentes localizaciones" 
set xtic rotate by -45
set bmargin 5
set xlabel "Velocidad de Viento (m/s)"
set ylabel "Frecuencia (Función de Distribución)"

set xrange[-0.1:18]
set yrange[0:0.7]
#set xlabel "Velocidad de Viento"
#set ylabel "Función de Distribución"
#set title "DISTRIBUCIÓN AJUSTADA DE WEIBULL"

k=1.234
C=2.845

F(x)=(k/C)*((x/C)**(k-1))*exp(-(x/C)**k)

plot F(x) w l lt 1 lw 2
replot F(x) w l lt 1 lw 2 title "El Alto - Bolivia"

#Alemania
K=2.4
c=11

G(x)=(K/c)*((x/c)**(K-1))*exp(-(x/c)**K)

replot G(x) w l lt 2 lw 2 title "Borkum - Alemania"

#Malaysia
a=0.858
b=0.002

H(x)=(a/b)*((x/b)**(a-1))*exp(-(x/b)**a)

replot H(x) w l lt 3 lw 2 title "Kebangsaan - Malaysia"

#Chile
c=2.2
d=6.5

I(x)=(c/d)*((x/d)**(c-1))*exp(-(x/d)**c)

replot I(x) w l lt 4 lw 2 title "Costa de Chile"


#Nigeria
e=2.1
f=4.6

J(x)=(e/f)*((x/f)**(e-1))*exp(-(x/f)**e)

replot J(x) w l lt 5 lw 2 title "Uyo - Nigeria"


#Colombia
g=0.489
h=2.644

L(x)=(g/h)*((x/h)**(g-1))*exp(-(x/h)**g)

replot L(x) w l lt 6 lw 2 title "Tunja - Colombia"


#Patacamaya
r=1.675
t=3.861

M(x)=(r/t)*((x/t)**(r-1))*exp(-(x/t)**r)

replot M(x) w l lt 7 lw 2 title "Patacamaya - Bolivia"
