#!/usr/bin/env python3
'''Assignment 4 Part 3'''
print(__doc__)

from colorsys import rgb_to_yiq
from typing import IO
import random

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

class Ellipse:
    '''Ellipse class'''
    def __init__(self, ell: tuple, col: tuple):
        self.cx: int = ell[0]                   # position x
        self.cy: int = ell[1]                   # position y
        self.radx: int = ell[2]                 # radius x
        self.rady: int = ell[3]                 # radius y
        self.red: int = col[0]                  # red RGB value
        self.green: int = col[1]                # green RGB value    
        self.blue: int = col[2]                 # blue RGB value
        
class ArtConfig:
    '''ArtConfig class'''
    def __init__(self, sha: int, cir: tuple, col: tuple, rec: tuple, ell: tuple):
        
        self.sha = sha                      # indicates the type of shape
        
        if (sha == 0):                      # if sha is 0 the constructs a circle
            shape = Circle(cir, col)
            self.shape = shape
        
        if (sha == 1):                      # if sha is 1 the constructs a rectangle
            shape = Rectangle(rec, col)
            self.shape = shape
        
        if (sha == 2):                      # if sha is 2 the constructs a ellipse
            shape = Ellipse(ell, col)
            self.shape = shape

class GenRandom:
    '''GenRandom class'''
    def __init__(self):

        sha = random.randint(0,4)                       # random value for type of shape
        x = random.randint(0,400)                       # random value for position x
        y = random.randint(0, 400)                      # random value for position y
        rad = random.randint(0,100)                     # random value for radius
        rx = random.randint(10,30)                      # random value for radius x
        ry = random.randint(10,30)                      # random value for radius y
        w = random.randint(10,100)                      # random value for width
        h = random.randint(10,100)                      # random value for height
        r = random.randint(0,255)                       # random value for RGB red value
        g = random.randint(0,255)                       # random value for RGB green value
        b = random.randint(0,255)                       # random value for RGB blue value
        op = round(random.uniform(0.0,1.0), 1)          # random value for opacity 
        
        
        self.sha = sha
        self.x = x
        self.y = y
        self.rad = rad 
        self.rx = rx 
        self.ry = ry
        self.w = w
        self.h = h
        self.r = r
        self.g = g
        self.b = b
        self.op = op

class ProEpilogue:
    '''ProEpilogue class'''
    def  __init__(self, file, canvas: tuple):
        self.file = file                        # file name
        self.canvas = canvas                    # canvas size

def writeHTMLcomment(f: IO[str], t: int, com: str): # writes a comment for HTML in file
    '''writeHTMLcomment method'''
    ts: str = "   " * t
    f.write(f'{ts}<!--{com}-->\n')
        
def drawCircleLine(f: IO[str], t: int, c: Circle):
    '''drawCircle method''' # writes line for drawing a circle in file
    ts: str = "   " * t
    line: str = f'<circle cx="{c.cx}" cy="{c.cy}" r="{c.rad}" fill="rgb({c.red}, {c.green}, {c.blue})" fill-opacity="{c.op}"></circle>'
    f.write(f"{ts}{line}\n")

def drawRectangleLine(f: IO[str], t: int, c: Rectangle):
    '''drawRectangleLine method''' # writes line for drawing a rectangle in file
    ts: str = "   " * t
    line: str = f'<rect x="{c.cx}" y="{c.cy}" width="{c.width}" height="{c.height}" style="fill:rgb({c.red}, {c.green}, {c.blue});fill-opacity:{c.op}" />' 
    f.write(f"{ts}{line}\n")

def drawEllipseLine(f: IO[str], t: int, c: Ellipse):
    '''drawEllipseLine method''' # writes line for drawing a Ellipse in file
    ts: str = "   " * t
    line: str = f'<ellipse cx="{c.cx}" cy="{c.cy}" rx="{c.radx}" ry="{c.rady}" style="fill:rgb({c.red}, {c.green}, {c.blue})" />'
    f.write(f"{ts}{line}\n")
        
def genArt(file: ProEpilogue, t: int):      # generates all the information for creating all of the art in the HTML file
   '''genART method'''
   
  
   size = file.canvas[0] * file.canvas[1]   # size of the canvas
   
   
   for i in range(random.randint(0,size)):      # loops through grabing random values for drawing random shapes
       table = GenRandom()                      # gets all nessesary information for shapes
       
    
       if (table.sha == 0):                     # if random number for sha is 0 it will draw a circle
           shape = ArtConfig(table.sha, (table.x, table.y, table.rad), (table.r, table.g, table.b, table.op), (table.x, table.y, table.w, table.h), (table.x, table.y, table.rx, table.ry))
           drawCircleLine(file.file, t, shape.shape)
       
       if (table.sha == 1):                     # if random number for sha is 1 it will draw a rectangle
           shape = ArtConfig(table.sha, (table.x, table.y, table.rad), (table.r, table.g, table.b, table.op), (table.x, table.y, table.w, table.h), (table.x, table.y, table.rx, table.ry))
           drawRectangleLine(file.file, t, shape.shape)
        
       if (table.sha == 2):                     # if random number for sha is 2 it will draw a ellipse
           shape = ArtConfig(table.sha, (table.x, table.y, table.rad), (table.r, table.g, table.b, table.op), (table.x, table.y, table.w, table.h), (table.x, table.y, table.rx, table.ry))
           drawEllipseLine(file.file, t, shape.shape)
        
        
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
    fnam: str = "a43.html"
    winTitle = "My Art"
    f: IO[str] = open(fnam, "w")
    canvas_size = (600,400)
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