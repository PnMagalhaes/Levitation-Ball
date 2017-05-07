*version 9.1 206455536
u 84
D? 2
R? 6
V? 2
M? 2
U? 2
? 2
@libraries
@analysis
.LIB C:\Users\ameli_000\Google Drive\Universidade\_E4\Regulador\2Abril.lib
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 2752 
@status
c 117:03:02:16:06:32;1491141992
n 0 117:03:02:16:06:18;1491141978 e 
s 0 117:03:02:16:06:18;1491141978 e 
*page 1 0 970 720 iA
@ports
port 33 EGND 345 200 h
port 43 EGND 420 245 h
port 32 EGND 605 245 h
@parts
part 25 r 435 225 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 u 13 0 15 25 hln 100 VALUE=470k
part 26 VDC 345 160 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 ap 9 0 -12 9 hcn 100 REFDES=V1
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 u 13 0 -11 18 hcn 100 DC=12
part 42 POT 420 245 v
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 sp 11 0 26 5 hln 100 PART=POT
a 0 ap 9 0 17 4 hln 100 REFDES=R5
a 0 u 0 0 30 28 hln 100 VALUE=500K
a 0 u 0 0 0 20 hln 100 SET=0.9
part 24 DbreakZ 545 180 d
a 0 a 0:13 0 0 0 hln 100 PKGREF=D1
a 0 sp 13 0 27 5 hln 100 MODEL=Dbreak
a 0 ap 9 0 17 -2 hln 100 REFDES=D1
part 27 IRF150 510 190 v
a 0 sp 0 0 10 40 hcn 100 MODEL=IRF150-X
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 sp 11 0 40 34 hcn 100 PART=IRF150
a 0 ap 9 0 9 18 hcn 100 REFDES=M1
a 0 a 0:13 0 0 0 hln 100 PKGREF=M1
part 28 r 605 230 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=RLOAD
a 0 xp 9 0 17 44 hln 100 REFDES=RLOAD
a 0 u 13 0 9 29 hln 100 VALUE=15
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 71 nodeMarker 605 160 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
@conn
w 45
a 0 up 0:33 0 0 0 hln 100 V=
s 420 160 420 205 53
s 345 160 420 160 44
a 0 up 33 0 382 159 hct 100 V=
s 420 160 490 160 50
w 66
a 0 up 0:33 0 0 0 hln 100 V=
s 440 225 435 225 62
a 0 up 33 0 435 234 hct 100 V=
w 39
a 0 up 0:33 0 0 0 hln 100 V=
s 510 225 475 225 4
a 0 up 33 0 492 224 hct 100 V=
s 510 190 510 225 72
s 545 225 510 225 40
s 545 210 545 225 74
w 77
a 0 up 0:33 0 0 0 hln 100 V=
s 545 160 545 180 35
s 605 160 545 160 8
a 0 up 33 0 574 159 hct 100 V=
s 545 160 530 160 37
s 605 160 605 190 13
w 83
s 605 230 605 245 81
@junction
j 475 225
+ p 25 2
+ w 39
j 345 200
+ p 26 -
+ s 33
j 420 245
+ p 42 1
+ s 43
j 420 205
+ p 42 2
+ w 45
j 345 160
+ p 26 +
+ w 45
j 420 160
+ w 45
+ w 45
j 440 225
+ p 42 t
+ w 66
j 435 225
+ p 25 1
+ w 66
j 510 190
+ p 27 g
+ w 39
j 490 160
+ p 27 d
+ w 45
j 605 160
+ p 71 pin1
+ w 77
j 510 225
+ w 39
+ w 39
j 545 210
+ p 24 2
+ w 39
j 545 180
+ p 24 1
+ w 77
j 530 160
+ p 27 s
+ w 77
j 545 160
+ w 77
+ w 77
j 605 190
+ p 28 2
+ w 77
j 605 230
+ p 28 1
+ w 83
j 605 245
+ s 32
+ w 83
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
