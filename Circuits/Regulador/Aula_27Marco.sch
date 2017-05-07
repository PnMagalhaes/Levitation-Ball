*version 9.1 3459177875
u 37
U? 2
D? 2
R? 5
L? 2
V? 2
M? 2
@libraries
@analysis
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
pageloc 1 0 2299 
@status
c 117:02:27:15:57:24;1490626644
*page 1 0 970 720 iA
@ports
port 8 EGND 400 280 h
port 11 EGND 155 145 h
@parts
part 3 DbreakZ 225 260 h
a 0 a 0:13 0 0 0 hln 100 PKGREF=D1
a 0 ap 9 0 15 0 hln 100 REFDES=D1
part 4 r 185 145 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 9 VDC 155 105 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 -12 9 hcn 100 REFDES=V1
part 10 IRF150 385 125 v
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=M1
a 0 sp 11 0 40 34 hcn 100 PART=IRF150
a 0 ap 9 0 9 18 hcn 100 REFDES=M1
part 16 r 480 180 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 25 26 hln 100 REFDES=R4
part 6 r 430 245 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 23 6 hln 100 REFDES=R3
a 0 u 13 0 13 5 hln 100 VALUE=1k
part 5 r 430 100 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 u 13 0 27 25 hln 100 VALUE=1k
a 0 ap 9 0 17 26 hln 100 REFDES=R2
part 2 OPAMP 270 140 h
a 0 sp 11 0 50 60 hln 100 PART=OPAMP
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
a 0 ap 9 0 14 0 hln 100 REFDES=U1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 13
s 385 125 385 160 12
s 385 160 350 160 14
w 22
s 480 95 430 95 23
s 430 95 405 95 27
s 430 100 430 95 24
s 480 95 480 140 21
w 28
s 430 205 430 200 30
s 270 180 270 200 32
s 430 200 430 140 36
s 270 200 430 200 34
@junction
j 155 145
+ s 11
+ p 9 -
j 385 125
+ p 10 g
+ w 13
j 350 160
+ p 2 OUT
+ w 13
j 405 95
+ p 10 s
+ w 22
j 430 100
+ p 5 1
+ w 22
j 430 95
+ w 22
+ w 22
j 480 140
+ p 16 2
+ w 22
j 430 205
+ p 6 2
+ w 28
j 430 140
+ p 5 2
+ w 28
j 270 180
+ p 2 -
+ w 28
j 430 200
+ w 28
+ w 28
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
