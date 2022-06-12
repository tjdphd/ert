set terminal postscript color
set output "AltVsNe03032020.ps"
set title "Electron Number Density by Altitude March 3, 2021 UT 11:00:00" font ",16"
set xlabel "Electron Number Density (m^{-3})"
set ylabel "Altitude (Km)"
show xlabel
show ylabel
plot "data1.dat" using 2:1 with lines
set output "AltVsNe03042020.ps"
set title "Electron Number Density by Altitude March 4, 2021 UT 23:00:00" font ",16"
set xlabel "Electron Number Density (m^{-3})"
set ylabel "Altitude (Km)"
show xlabel
show ylabel
plot "data2.dat" using 2:1 with lines
