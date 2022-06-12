set terminal postscript color
set output "myplot.ps"
set title "Electron Number Density by Altitude" font ",14"
set xlabel "Electron Number Density (m^-3)"
set ylabel "Altitude (Km)"
show xlabel
show ylabel
plot "data.dat" using 2:1 with lines
