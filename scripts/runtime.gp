reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.080]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.11):($2+0.005):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'SmallerStruct'  , \
'' using ($0+0.02):($3+0.01):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'HashSDBM'  , \
'' using ($0+0.13):($4+0.015):4 with labels title ' ', \
'' using 5:xtic(1) with histogram title 'HashBKDR'  , \
'' using ($0+0.24):($5+0.02):5 with labels title ' ', \
'' using 6:xtic(1) with histogram title 'NewSize'  , \
'' using ($0+0.35):($6+0.025):6 with labels title ' '

