import sys

class Solver(object):
    # Read file and return its content
    def readFile(self, file_name):

        purify=lambda x: x.split("\n")[0].split(" ")

        matrix = []
        with open(file_name, "r") as file:
            row_col = file.readline()
            # Get first row and split into two pieces ROW,COLUMN
            row_col = purify(row_col)
            row, col = list(map(lambda x: int(x), row_col))
            self.size = (row, col)

            # Load content and create matrix
            for _ in range(col):
                content = purify(file.readline())
                matrix.append(content)
        return matrix

    def checkCoordinates(self, x, y):
        return (x >= 0 and y >= 0 and x < self.size[0] and y < self.size[1])

    def loop(self, a, b):
        x,y=a,b
        memx,memy=a,b
        self.lenghtMatrix[x][y] = 0
        tfmatrix=[[False]*self.size[0] for _ in range(self.size[1])]
        
        # Move on given array path and move L,R,U,D
        # When it is possible move to that coordinates and block via tfmatrix

        while (self.checkCoordinates(x,y)):
            tfmatrix[x][y] = True 
            if (self.lenghtMatrix[x][y] != -1):
                if (self.lenghtMatrix[memx][memy] < self.lenghtMatrix[x][y]):
                    self.lenghtMatrix[memx][memy] = self.lenghtMatrix[x][y]
                    break

            self.lenghtMatrix[memx][memy] += 1
            self.lenghtMatrix[x][y] = self.lenghtMatrix[memx][memy]
            
            if (y < self.size[0] - 1 and ((self.content[x][y]) == self.content[x][y + 1]) and tfmatrix[x][y + 1]==False):
                y += 1
                continue 

            if (y>=0 and (self.content[x][y] == self.content[x][y - 1]) and tfmatrix[x][y - 1]==False ):
                y -= 1
                continue

            if (x>0 and (self.content[x][y] == self.content[x - 1][y]) and (tfmatrix[x - 1][y]==False)): 
                x -= 1
                continue 

            if (x < self.size[1] - 1 and (self.content[x][y] == self.content[x + 1][y]) and (tfmatrix[x + 1][y]==False)):
                x += 1
                continue
            break

        return self.lenghtMatrix[memx][memy]

    def solve(self):

        maxiPath = 1

        for a in range(self.size[0]):
            for b in range(self.size[1]):
                if (self.lenghtMatrix[a][b] == -1):
                    self.lenghtMatrix[a][b]  = self.loop(a, b)

                maxiPath = max(maxiPath, self.lenghtMatrix[a][b])
                if (maxiPath == self.size[0]*self.size[1]):
                    return maxiPath
        return maxiPath 

    def __init__(self, file_name):
        self.size = (0, 0)  # row,col
        self.content = self.readFile(file_name)
        self.lenghtMatrix = [[-1]*self.size[1] for _ in range(self.size[0])]


if(__name__=="__main__"):
    fileNames=sys.argv[1:]
    for fileName in fileNames:
        solv = Solver("../tests/"+fileName)
        print(solv.solve())

