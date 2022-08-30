#!/usr/bin/env python3
'''Assignment 4 Part 1'''
print(__doc__)

from typing import IO

class Circle:
    '''Circle class'''
    def __init__(self, cir: tuple, col: tuple):
        self.cx: int = cir[0]                   # position x
        self.cy: int = cir[1]                   # position y
        self.rad: int = cir[2]                  # radius
        self.red: int = col[0]                  # red RGB value
        self.green: int = col[1]                # green RGB value
        self.blue: int = col[2]                 # blue RGB value
        self.op: float = col[3]                 # shape opacity

class Rectangle:
    '''Rectangle class'''
    def __init__(self, rec: tuple, col: tuple):
        self.cx: int = rec[0]                   # position x
        self.cy: int = rec[1]                   # position y
        self.width: int = rec[2]                # width
        self.height: int = rec[3]               # height
        self.red: int = col[0]                  # red RGB value
        self.green: int = col[1]                # green RGB value
        self.blue: int = col[2]                 # blue RGB value
        self.op: float = col[3]                 # shape opacity


class ProEpilogue:
    '''ProEpilogue class'''
    def  __init__(self, file, canvas: tuple):
        self.file = file                        # file name
        self.canvas = canvas                    # canvas size
        
def writeHTMLcomment(f: IO[str], t: int, com: str):     # writes a comment for HTML in file
    '''writeHTMLcomment method'''
    ts: str = "   " * t
    f.write(f'{ts}<!--{com}-->\n')
        
def drawCircleLine(f: IO[str], t: int, c: Circle):      # writes line for drawing a circle in file
    '''drawCircle method'''
    ts: str = "   " * t
    line: str = f'<circle cx="{c.cx}" cy="{c.cy}" r="{c.rad}" fill="rgb({c.red}, {c.green}, {c.blue})" fill-opacity="{c.op}"></circle>'
    f.write(f"{ts}{line}\n")

def drawRectangleLine(f: IO[str], t: int, c: Rectangle):    # writes line for drawing a rectangle in file
    ts: str = "   " * t
    line: str = f'<rect x="{c.cx}" y="{c.cy}" width="{c.width}" height="{c.height}" style="fill:rgb({c.red}, {c.green}, {c.blue});fill-opacity:{c.op}" />'  
    f.write(f"{ts}{line}\n")
        
def genArt(file: ProEpilogue, t: int):  # generates all the information for creating all of the art in the HTML file
   '''genART method'''
   drawCircleLine(file.file, t, Circle((50,50,50), (255,0,0,1.0)))
   drawCircleLine(file.file, t, Circle((150,50,50), (255,0,0,1.0)))
   drawCircleLine(file.file, t, Circle((250,50,50), (255,0,0,1.0)))
   drawCircleLine(file.file, t, Circle((350,50,50), (255,0,0,1.0)))
   drawCircleLine(file.file, t, Circle((450,50,50), (255,0,0,1.0)))
   drawCircleLine(file.file, t, Circle((50,250,50), (0,0,255,1.0)))
   drawCircleLine(file.file, t, Circle((150,250,50), (0,0,255,1.0)))
   drawCircleLine(file.file, t, Circle((250,250,50), (0,0,255,1.0)))
   drawCircleLine(file.file, t, Circle((350,250,50), (0,0,255,1.0)))
   drawCircleLine(file.file, t, Circle((450,250,50), (0,0,255,1.0)))
   drawRectangleLine(file.file, t, Rectangle((154, 154, 2000,700), (14, 128, 235, 1.0)))
        
def openSVGcanvas(file: ProEpilogue, t: int):   # writes the opening text for SVG in file
     '''openSVGcanvas method'''
     ts: str = "   " * t
     writeHTMLcomment(file.file, t, "Define SVG drawing box")
     file.file.write(f'{ts}<svg width="{file.canvas[0]}" height="{file.canvas[1]}">\n')

def closeSVGcanvas(file: ProEpilogue, t: int):  # writes the closing text for SVG and HTML in file
    '''closeSVGcanvas method'''
    ts: str = "   " * t
    file.file.write(f'{ts}</svg>\n')
    file.file.write(f'</body>\n')
    file.file.write(f'</html>\n')

def writeHTMLline(file: ProEpilogue, t: int, line: str):    # writes the title for HTML in file
     '''writeLineHTML method'''
     ts = "   " * t
     file.file.write(f"{ts}{line}\n")

def writeHTMLHeader(file: ProEpilogue, winTitle: str):      # writes the opening text for HTML in file
    '''writeHeadHTML method'''
    writeHTMLline(file, 0, "<html>")
    writeHTMLline(file, 0, "<head>")
    writeHTMLline(file, 1, f"<title>{winTitle}</title>")
    writeHTMLline(file, 0, "</head>")
    writeHTMLline(file, 0, "<body>")

def writeHTMLfile():                                        # constructs HTML file by writing into the HTML file
    '''writeHTMLfile method'''
    fnam: str = "a41.html"
    winTitle = "My Art"
    f: IO[str] = open(fnam, "w")
    canvas_size = (500,300)
    epipro = ProEpilogue(f, canvas_size)
    
    writeHTMLHeader(epipro, winTitle)
    openSVGcanvas(epipro, 1)
    genArt(epipro, 2)
    closeSVGcanvas(epipro, 1)
    f.close()

def main():
    '''main method'''
    writeHTMLfile()

main()

                                                                                                                                                                                                                                                                                                        
