## Catan C Impl

Just for kicks, I decided to write Settlers of Catan in C! Initially, this will just be a project for fun and pleasure.

Local play only, text-based. Maybe I'll think about making a little hand-held thing with a screen at some point. How hard can it be!

For now, this Readme will mostly be notes and planning. To be updated later as the project progresses.

Writing this in C will hopefully be a good chance for me to implement some OOP ideas in the language.

## Rules of Catan

Settlers of Catan is a strategy game wherein the goal is to amass victory points up to a totalof 10 to win

Victory points are aquired in several ways - through settlements (1p), cities(2p), development cards (1p), and the two "special" accolades - largest army and longest road (2p ea.)

The game is played on a hexagonal board with 19 tiles, 18 of which are coded to produce a given resource. At the start of a game, each tile is placed randomly in the hexagonal grid shape, the borders of which contain ports - areas in which a player who controls the ports can 
## Files and components

Board generation:
 - Fisher-yates shuffle (edges)
 - Same for tiles and dice values

## Board Drawing:
 - ASCII art (lol)
 ### Board outline:    

```
[0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19]
[1 1 1 0 0 0 0 0 0 0  0  0  1  1  0  0  0  0  0  0]
[2]
[3]
[4]
[5]
[6]
[7]
[8]
[9]
[10]
[11]
[12]
[13]
[14]
[15]
[16]
[17]
[18]
[19]
```
 ```         
oooooooooooooooooo**************oooooooooooooooooo
ooooooooooooooo********************ooooooooooooooo
oooooooooooo********** ---- **********oooooooooooo
ooooooooo*********** /      \ ***********ooooooooo
oooooo********* ----(   2    )---- *********oooooo
ooo********** /      \      /      \ **********ooo
******** ----(   1    )----(   3    )---- ********  
****** /      \      /      \      /      \ ******
***** (   0    )----(    7   )----(   4    ) *****
****** \      /      \      /      \      / ******
******* )----(    6   )----(    8   )----( *******
****** /      \      /      \      /      \ ******
***** (   5    )----(   12   )----(    9   ) *****
****** \      /      \      /      \      / ******
******* )----(   11   )----(   13   )----( *******
****** /      \      /      \      /      \ ******
***** (   10   )----(   16   )----(   14   ) *****
****** \      /      \      /      \      / ******
*******  ----(   15   )----(   17   )----  *******
ooo********** \      /      \      / **********ooo
oooooo********* ----(   18   )----  ********oooooo
ooooooooo*********** \      / ***********ooooooooo
oooooooooooo********** ---- **********oooooooooooo
ooooooooooooooo********************ooooooooooooooo
oooooooooooooooooo**************oooooooooooooooooo

```
14 wide +3(6)(2) = 50


24 rows * 50 = 1200 chars     


hex 10 chars wide                            
### resource tiles
brick:
```
   ----
 /bbbbbb\
(b      b)
 \bbbbbb/
   ----
```
wood:
```
   ----
 /wwwwww\
(w      w)
 \wwwwww/
   ----
```
wheat:
```
   ----
 /whwhwh\
(wh    wh)
 \whwhwh/
   ----
```
ore:
```
   ----
 /oooooo\
(o      o)
 \oooooo/
   ----
```
sheep:
```
   ----
 /ssssss\
(s      s)
 \ssssss/
   ----
```
experimant:
```
   )--------(              )--------( 
  /          \            /          \     
 /            \          /   
(              )--------( )
 \            /
  \          /
   )--------(
```