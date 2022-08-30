#!/usr/bin/env python3
'''Assignment 4 Part 2'''
print(__doc__)



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


def maketable():                                                                            # constructs table of vaules for shapes
    '''maketable method'''
    header = ["CNT", "SHA", "X", "Y", "RAD", "RX", "RY", "W", "H", "R", "G", "B", "OP"]     # title for each column
    format_row = "{:>5}" * (len(header) + 1)                                                # evenly spaces out the table
    print(format_row.format("", *header))                                                   # prints 1st row containing the titles
    
    for i in range(0,10):                                                                   # loops through generating random values for shape and prints them out row by row
        shape = GenRandom()
        x = [i, shape.sha, shape.x, shape.y, shape.rad, shape.rx, shape.ry, shape.w, shape.h, shape.r, shape.g, shape.b, shape.op]
        print(format_row.format("", *x))

def main():
    '''main method'''
    
    maketable()

main()