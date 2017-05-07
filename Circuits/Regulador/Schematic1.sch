*version 9.1 2308062865
u 133
M? 3
L? 3
V? 3
? 9
R? 3
@libraries
@analysis
.TRAN 1 0 0 0
+0 0ns
+1 10us
.OP 0 
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
pageloc 1 0 2727 
@status
n 0 117:02:20:14:15:53;1490019353 e 
s 2832 117:02:20:14:15:57;1490019357 e 
c 117:02:20:14:11:13;1490019073
*page 1 0 970 720 iA
@ports
port 22 EGND 195 190 h
port 11 BUBBLE 305 120 d
a 1 x 3 0 0 0 hcn 100 LABEL=Vout
port 6 EGND 215 100 h
port 4 EGND 280 190 h
@parts
part 90 L 280 40 d
a 0 u 13 0 33 1 hln 100 VALUE=3.5mH
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L2
a 0 ap 9 0 21 -2 hln 100 REFDES=L2
part 5 VDC 215 50 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 -12 9 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=12
part 21 VPULSE 195 150 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=PWM
a 1 xp 9 0 -10 24 hcn 100 REFDES=PWM
a 1 u 0 0 0 0 hcn 100 V1=0
a 1 u 0 0 0 0 hcn 100 TD=10n
a 1 u 0 0 0 0 hcn 100 TR=100p
a 1 u 0 0 0 0 hcn 100 TF=100p
a 1 u 0 0 0 0 hcn 100 V2=10
a 1 u 0 0 0 0 hcn 100 PER=1u
a 1 u 0 0 0 0 hcn 100 PW=0.5u
part 50 IRF150 250 145 h
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=M2
a 0 ap 9 0 49 18 hcn 100 REFDES=M2
a 0 sp 11 0 50 26 hcn 100 PART=IRF150
part 37 r 210 145 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=1M
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 120 nodeMarker 200 145 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=8
part 89 iMarker 280 120 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=7
@conn
w 106
a 0 up 0:33 0 0 0 hln 100 V=
s 215 90 215 100 109
a 0 up 33 0 217 95 hlt 100 V=
w 105
a 0 up 0:33 0 0 0 hln 100 V=
s 215 40 215 50 116
s 215 40 280 40 101
a 0 up 33 0 259 39 hct 100 V=
w 28
a 0 up 0:33 0 0 0 hln 100 V=
s 195 145 195 150 27
s 195 145 200 145 77
a 0 up 33 0 202 144 hct 100 V=
s 200 145 210 145 121
w 17
a 0 up 0:33 0 0 0 hln 100 V=
s 280 120 305 120 18
a 0 up 33 0 306 125 hct 100 V=
s 280 100 280 120 119
s 280 120 280 125 91
w 13
a 0 up 0:33 0 0 0 hln 100 V=
s 280 165 280 190 69
a 0 up 33 0 282 170 hlt 100 V=
@junction
j 210 145
+ p 37 1
+ w 28
j 305 120
+ s 11
+ w 17
j 280 100
+ p 90 2
+ w 17
j 215 90
+ p 5 -
+ w 106
j 215 100
+ s 6
+ w 106
j 280 40
+ p 90 1
+ w 105
j 215 50
+ p 5 +
+ w 105
j 280 120
+ p 89 pin1
+ w 17
j 200 145
+ p 120 pin1
+ w 28
j 280 190
+ s 4
+ w 13
j 250 145
+ p 50 g
+ p 37 2
j 280 125
+ p 50 d
+ w 17
j 280 165
+ p 50 s
+ w 13
j 195 150
+ p 21 +
+ w 28
j 195 190
+ s 22
+ p 21 -
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
