# Solution to Assessement IRI EDP

This repository contains work related to the rd-sci coding assessments document


In the following I describe how I produced plots AltVsNe03032021.pdf and AltVsNe03042021.pdf
These steps are currently only certain to work on my early 2012 Macbook Pro under macOS 10.13.6 
but any errors arising should only required modest edits to the sources.

Steps:

- clone this repository git clone https://github.com/tjdphd/ert.git
- navigate to the repository in a mac terminal
- execute ```make```
- execute ```.\testiri```
- execute ```gnuplot plotNe.gp```
- execute ```ps2pdf AltVsNe03032021.ps```
- execute ```ps2pdf AltVsNe03042021.ps```


