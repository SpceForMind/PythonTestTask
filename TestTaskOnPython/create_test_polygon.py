
import os

def CreateTestPolygon(matrix_ways):
    root = os.getcwd() + '/'
    new_dir = root

    for way in matrix_ways:
        for particular_way in way:
            if str(particular_way).endswith('.txt'):
                open(new_dir + str(particular_way), 'w')
            else:
                new_dir +=  str(particular_way) + '/'
                #print(new_dir)
                if not os.path.isdir(new_dir):
                    os.mkdir(new_dir)
        new_dir = root


way_to_create_files = input().split()
matrix_ways = []

for way in way_to_create_files:
    matrix_ways += [str(way).split('/')]

CreateTestPolygon(matrix_ways)
