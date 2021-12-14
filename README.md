# mario
An Adaptive Mesh Refinement I/O Analyzer

## Installation
```
$ git clone git@github.com:jungwonkim/mario.git
$ cd mario
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=<installation_dir>
$ make install
```

## Tools
### Mario-Castro
```
$ cd ~/work/Castro/Exec/hydro_tests/Sedov/sedov_2d_cyl
$ ls
sedov_2d_cyl_in_cart_chk00000  sedov_2d_cyl_in_cart_chk00160  sedov_2d_cyl_in_cart_plt00100
sedov_2d_cyl_in_cart_chk00020  sedov_2d_cyl_in_cart_chk00180  sedov_2d_cyl_in_cart_plt00120
sedov_2d_cyl_in_cart_chk00040  sedov_2d_cyl_in_cart_chk00200  sedov_2d_cyl_in_cart_plt00140
sedov_2d_cyl_in_cart_chk00060  sedov_2d_cyl_in_cart_plt00000  sedov_2d_cyl_in_cart_plt00160
sedov_2d_cyl_in_cart_chk00080  sedov_2d_cyl_in_cart_plt00020  sedov_2d_cyl_in_cart_plt00180
sedov_2d_cyl_in_cart_chk00100  sedov_2d_cyl_in_cart_plt00040  sedov_2d_cyl_in_cart_plt00200
sedov_2d_cyl_in_cart_chk00120  sedov_2d_cyl_in_cart_plt00060
sedov_2d_cyl_in_cart_chk00140  sedov_2d_cyl_in_cart_plt00080

$ mario-castro <path> [categories (1: Step, 2: Level, 4: Rank)]
$ mario-castro . 1
== . ==
Step [    0]: FileSize [   1950295]
Step [   20]: FileSize [   1950295]
Step [   40]: FileSize [   2298722]
Step [   60]: FileSize [   5363048]
Step [   80]: FileSize [   9123176]
Step [  100]: FileSize [  13161832]
Step [  120]: FileSize [  17409384]
Step [  140]: FileSize [  22979948]
Step [  160]: FileSize [  28620140]
Step [  180]: FileSize [  35722604]
Step [  200]: FileSize [  42755432]

$ mario-castro . 2
== . ==
Levl [    0]: FileSize [  12258928]
Levl [    1]: FileSize [  12815279]
Levl [    2]: FileSize [  35097611]
Levl [    3]: FileSize [ 121163058]

$ mario-castro . 4
== . ==
Rank [    0]: FileSize [  45751587]
Rank [    1]: FileSize [  46726367]
Rank [    2]: FileSize [  43801640]
Rank [    3]: FileSize [  45055282]

$ mario-castro . 1 4
== . ==
Step  [    0]
 Rank [    0]: FileSize [    557228]
 Rank [    1]: FileSize [    557229]
 Rank [    2]: FileSize [    278612]
 Rank [    3]: FileSize [    557226]
Step  [   20]
 Rank [    0]: FileSize [    557228]
 Rank [    1]: FileSize [    557229]
 Rank [    2]: FileSize [    278612]
 Rank [    3]: FileSize [    557226]
Step  [   40]
 Rank [    0]: FileSize [    696581]
 Rank [    1]: FileSize [    557229]
 Rank [    2]: FileSize [    417965]
 Rank [    3]: FileSize [    626947]
Step  [   60]
 Rank [    0]: FileSize [   1392985]
 Rank [    1]: FileSize [   1741146]
 Rank [    2]: FileSize [   1253723]
 Rank [    3]: FileSize [    975194]
Step  [   80]
 Rank [    0]: FileSize [   2089305]
 Rank [    1]: FileSize [   2367833]
 Rank [    2]: FileSize [   2228570]
 Rank [    3]: FileSize [   2437468]
Step  [  100]
 Rank [    0]: FileSize [   3412312]
 Rank [    1]: FileSize [   2924891]
 Rank [    2]: FileSize [   3203418]
 Rank [    3]: FileSize [   3621211]
Step  [  120]
 Rank [    0]: FileSize [   3899737]
 Rank [    1]: FileSize [   5083481]
 Rank [    2]: FileSize [   4317530]
 Rank [    3]: FileSize [   4108636]
Step  [  140]
 Rank [    0]: FileSize [   5431641]
 Rank [    1]: FileSize [   6127965]
 Rank [    2]: FileSize [   5710171]
 Rank [    3]: FileSize [   5710171]
Step  [  160]
 Rank [    0]: FileSize [   7102808]
 Rank [    1]: FileSize [   7311709]
 Rank [    2]: FileSize [   7102811]
 Rank [    3]: FileSize [   7102812]
Step  [  180]
 Rank [    0]: FileSize [   9609561]
 Rank [    1]: FileSize [   9191772]
 Rank [    2]: FileSize [   8147291]
 Rank [    3]: FileSize [   8773980]
Step  [  200]
 Rank [    0]: FileSize [  11002201]
 Rank [    1]: FileSize [  10305883]
 Rank [    2]: FileSize [  10862937]
 Rank [    3]: FileSize [  10584411]
 
$ mario-castro . 4 1
== . ==
Rank  [    0]
 Step [    0]: FileSize [    557228]
 Step [   20]: FileSize [    557228]
 Step [   40]: FileSize [    696581]
 Step [   60]: FileSize [   1392985]
 Step [   80]: FileSize [   2089305]
 Step [  100]: FileSize [   3412312]
 Step [  120]: FileSize [   3899737]
 Step [  140]: FileSize [   5431641]
 Step [  160]: FileSize [   7102808]
 Step [  180]: FileSize [   9609561]
 Step [  200]: FileSize [  11002201]
Rank  [    1]
 Step [    0]: FileSize [    557229]
 Step [   20]: FileSize [    557229]
 Step [   40]: FileSize [    557229]
 Step [   60]: FileSize [   1741146]
 Step [   80]: FileSize [   2367833]
 Step [  100]: FileSize [   2924891]
 Step [  120]: FileSize [   5083481]
 Step [  140]: FileSize [   6127965]
 Step [  160]: FileSize [   7311709]
 Step [  180]: FileSize [   9191772]
 Step [  200]: FileSize [  10305883]
Rank  [    2]
 Step [    0]: FileSize [    278612]
 Step [   20]: FileSize [    278612]
 Step [   40]: FileSize [    417965]
 Step [   60]: FileSize [   1253723]
 Step [   80]: FileSize [   2228570]
 Step [  100]: FileSize [   3203418]
 Step [  120]: FileSize [   4317530]
 Step [  140]: FileSize [   5710171]
 Step [  160]: FileSize [   7102811]
 Step [  180]: FileSize [   8147291]
 Step [  200]: FileSize [  10862937]
Rank  [    3]
 Step [    0]: FileSize [    557226]
 Step [   20]: FileSize [    557226]
 Step [   40]: FileSize [    626947]
 Step [   60]: FileSize [    975194]
 Step [   80]: FileSize [   2437468]
 Step [  100]: FileSize [   3621211]
 Step [  120]: FileSize [   4108636]
 Step [  140]: FileSize [   5710171]
 Step [  160]: FileSize [   7102812]
 Step [  180]: FileSize [   8773980]
 Step [  200]: FileSize [  10584411]
 
$ mario-castro . 4 1 2
== . ==
Rank   [    0]
 Step  [    0]
  Levl [    0]: FileSize [    278611]
  Levl [    2]: FileSize [    278617]
 Step  [   20]
  Levl [    0]: FileSize [    278611]
  Levl [    2]: FileSize [    278617]
 Step  [   40]
  Levl [    0]: FileSize [    278611]
  Levl [    2]: FileSize [    278617]
  Levl [    3]: FileSize [    139353]
 Step  [   60]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    278616]
  Levl [    3]: FileSize [    557145]
 Step  [   80]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    417880]
  Levl [    3]: FileSize [   1114201]
 Step  [  100]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [   1114199]
  Levl [    3]: FileSize [   1740889]
 Step  [  120]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    835672]
  Levl [    3]: FileSize [   2506841]
 Step  [  140]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    626773]
  Levl [    2]: FileSize [   1114200]
  Levl [    3]: FileSize [   3412057]
 Step  [  160]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    626773]
  Levl [    2]: FileSize [   1740887]
  Levl [    3]: FileSize [   4456537]
 Step  [  180]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    557142]
  Levl [    2]: FileSize [   2506839]
  Levl [    3]: FileSize [   6266969]
 Step  [  200]
  Levl [    0]: FileSize [    278611]
  Levl [    1]: FileSize [    557142]
  Levl [    2]: FileSize [   1740889]
  Levl [    3]: FileSize [   8425559]
Rank   [    1]
 Step  [    0]
  Levl [    0]: FileSize [    278612]
  Levl [    3]: FileSize [    278617]
 Step  [   20]
  Levl [    0]: FileSize [    278612]
  Levl [    3]: FileSize [    278617]
 Step  [   40]
  Levl [    0]: FileSize [    278612]
  Levl [    3]: FileSize [    278617]
 Step  [   60]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [     69717]
  Levl [    2]: FileSize [    278616]
  Levl [    3]: FileSize [   1114201]
 Step  [   80]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [     69717]
  Levl [    2]: FileSize [    626775]
  Levl [    3]: FileSize [   1392729]
 Step  [  100]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    278617]
  Levl [    3]: FileSize [   2089049]
 Step  [  120]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [   1114199]
  Levl [    3]: FileSize [   3412057]
 Step  [  140]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278615]
  Levl [    2]: FileSize [   1114201]
  Levl [    3]: FileSize [   4456537]
 Step  [  160]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278615]
  Levl [    2]: FileSize [   1114201]
  Levl [    3]: FileSize [   5640281]
 Step  [  180]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278615]
  Levl [    2]: FileSize [   1671256]
  Levl [    3]: FileSize [   6963289]
 Step  [  200]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278615]
  Levl [    2]: FileSize [   2089048]
  Levl [    3]: FileSize [   7659608]
Rank   [    2]
 Step  [    0]
  Levl [    0]: FileSize [    278612]
 Step  [   20]
  Levl [    0]: FileSize [    278612]
 Step  [   40]
  Levl [    0]: FileSize [    278612]
  Levl [    3]: FileSize [    139353]
 Step  [   60]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    139349]
  Levl [    2]: FileSize [    278617]
  Levl [    3]: FileSize [    557145]
 Step  [   80]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    139349]
  Levl [    2]: FileSize [    417880]
  Levl [    3]: FileSize [   1392729]
 Step  [  100]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    557144]
  Levl [    3]: FileSize [   2089049]
 Step  [  120]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    835672]
  Levl [    3]: FileSize [   2924633]
 Step  [  140]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    417878]
  Levl [    2]: FileSize [   1114200]
  Levl [    3]: FileSize [   3899481]
 Step  [  160]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [    417878]
  Levl [    2]: FileSize [   1392728]
  Levl [    3]: FileSize [   5013593]
 Step  [  180]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [   1114197]
  Levl [    2]: FileSize [   1114201]
  Levl [    3]: FileSize [   5640281]
 Step  [  200]
  Levl [    0]: FileSize [    278612]
  Levl [    1]: FileSize [   1114197]
  Levl [    2]: FileSize [   2506839]
  Levl [    3]: FileSize [   6963289]
Rank   [    3]
 Step  [    0]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    278613]
 Step  [   20]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    278613]
 Step  [   40]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    278613]
  Levl [    3]: FileSize [     69721]
 Step  [   60]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    139349]
  Levl [    2]: FileSize [    278615]
  Levl [    3]: FileSize [    278617]
 Step  [   80]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    139349]
  Levl [    2]: FileSize [    278617]
  Levl [    3]: FileSize [   1740889]
 Step  [  100]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    557144]
  Levl [    3]: FileSize [   2506841]
 Step  [  120]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    278613]
  Levl [    2]: FileSize [    626777]
  Levl [    3]: FileSize [   2924633]
 Step  [  140]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    417878]
  Levl [    2]: FileSize [   1114199]
  Levl [    3]: FileSize [   3899481]
 Step  [  160]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    417878]
  Levl [    2]: FileSize [   1392728]
  Levl [    3]: FileSize [   5013593]
 Step  [  180]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    557142]
  Levl [    2]: FileSize [   1671256]
  Levl [    3]: FileSize [   6266969]
 Step  [  200]
  Levl [    0]: FileSize [    278613]
  Levl [    1]: FileSize [    557142]
  Levl [    2]: FileSize [   2089048]
  Levl [    3]: FileSize [   7659608]
```

### Mario-Castro-Weights
```
$ cd ~/work/Castro/Exec/hydro_tests/Sedov/sedov_2d_cyl
$ ls
sedov_2d_cyl_in_cart_chk00000  sedov_2d_cyl_in_cart_chk00160  sedov_2d_cyl_in_cart_plt00100
sedov_2d_cyl_in_cart_chk00020  sedov_2d_cyl_in_cart_chk00180  sedov_2d_cyl_in_cart_plt00120
sedov_2d_cyl_in_cart_chk00040  sedov_2d_cyl_in_cart_chk00200  sedov_2d_cyl_in_cart_plt00140
sedov_2d_cyl_in_cart_chk00060  sedov_2d_cyl_in_cart_plt00000  sedov_2d_cyl_in_cart_plt00160
sedov_2d_cyl_in_cart_chk00080  sedov_2d_cyl_in_cart_plt00020  sedov_2d_cyl_in_cart_plt00180
sedov_2d_cyl_in_cart_chk00100  sedov_2d_cyl_in_cart_plt00040  sedov_2d_cyl_in_cart_plt00200
sedov_2d_cyl_in_cart_chk00120  sedov_2d_cyl_in_cart_plt00060
sedov_2d_cyl_in_cart_chk00140  sedov_2d_cyl_in_cart_plt00080

$ mario-castro-weights <path>
$ mario-castro-weights .
[D] MARIO [Repository.cpp:191:Formula] nsteps[25] step_diff[10] val0[1950295] val1[51842849]
[D] MARIO [Repository.cpp:199:Formula] linear[1995702.160000] datagrowth[1.140207] quadratic[798.280864] cubic[3.193123] log[20806422.937841]
Step      AMReX     Linear DataGrowth  Quadratic      Cubic        Log
   0    1950295    1950295    1950295    1950295    1950295    1950295
  10    1950295    3945997    2223739    2030123    1953488   22756717
  20    1950295    5941699    2535521    2269607    1975839   29020075
  30    1950295    7937401    2891017    2668747    2036509   32683904
  40    2298722    9933103    3296356    3227544    2154654   35283432
  50    3134573   11928805    3758526    3945997    2349435   37299783
  60    5363048   13924507    4285496    4824106    2640009   38947261
  70    6268264   15920209    4886350    5861871    3045536   40340185
  80    9123176   17915911    5571448    7059292    3585174   41546790
  90   11699560   19911613    6352601    8416369    4278081   42611091
 100   13161832   21907315    7243277    9933103    5143418   43563140
 110   15668584   23903017    8258832   11609493    6200342   44424374
 120   17409384   25898719    9416774   13445539    7468012   45210619
 130   22979948   27894421   10737067   15441241    8965587   45933894
 140   22979948   29890123   12242474   17596599   10712225   46603542
 150   26322284   31885825   13958949   19911614   12727086   47226970
 160   28620140   33881527   15916085   22386285   15029328   47810147
 170   33146220   35877229   18147624   25020611   17638110   48357958
 180   35722604   37872931   20692040   27814594   20572590   48874448
 190   39900520   39868633   23593200   30768234   23851928   49363006
 200   42755432   41864335   26901121   33881529   27495282   49826498
 210   42755432   43860037   30672835   37154481   31521811   50267371
 220   44688159   45855739   34973368   40587088   35950673   50687731
 230   47073145   47851441   39876864   44179352   40801028   51089403
 240   50972536   49847143   45467862   47931272   46092033   51473976
 250   51842849   51842845   51842755   51842848   51842849   51842848
Weights              0.340      0.000      0.660      0.000      0.000
```
