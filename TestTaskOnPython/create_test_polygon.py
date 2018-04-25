
import os
import argparse

def CreateTestPolygon(matrix_ways):
    root = os.getcwd() + '/'
    new_dir = root
    
    for way in matrix_ways:
        matrix_embded_way = []
        matrix_embded_way += os.path.split(way)[0].split('/')
        for embded_way in matrix_embded_way:
            new_dir += embded_way + '/'
            if not os.path.isdir(new_dir):
                os.mkdir(new_dir)
        file_name = os.path.split(way)[1]
        if file_name.endswith('.txt'):
            new_file =  open(new_dir + '/' + file_name, 'w')
            new_file.close()
        new_dir = root

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('ways', nargs = '+')
    namespace = parser.parse_args()
    
    matrix_ways = []

    for way in namespace.ways:
       matrix_ways.append(str(way))
    CreateTestPolygon(matrix_ways)
