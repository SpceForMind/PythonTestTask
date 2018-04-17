
import os
import sys

def CreateTestPolygon(matrix_ways):
    root = os.getcwd() + '/'
    new_dir = root

    for way in matrix_ways:
        new_dir += os.path.split(str(way))[0]
        file_name = os.path.split(str(way))[1]
        if not os.path.isdir(new_dir):
            os.mkdir(new_dir)
        if file_name.endswith('.txt'):
            with open(new_dir + '/' + file_name, 'w') as f:
                f.close()
        new_dir = root

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("No way for files!\n")
        sys.exit(1)
    
    matrix_ways = []

    for way in sys.argv:
       matrix_ways.append(str(way))

    CreateTestPolygon(matrix_ways)
