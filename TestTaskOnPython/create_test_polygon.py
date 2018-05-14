
import os
import argparse
import random

#options for create files system 
ROOTDIR = 'root'
FILE_NAMES = 'ABCDEFGHIGKLMNOPQRSTUVWXYZ'
DIR_NAMES = ['Dir1', 'Dir2', 'Dir3', 'Dir4', 'Dir5']
COUNT_FILES = 50
DEEP = 6

def CreateTestPolygon():
    root = os.path.join(os.getcwd(), ROOTDIR)
    if not os.path.isdir(root):
        os.mkdir(root)
    new_dir = root
    new_file = root #complusory part of way

    for i in range(COUNT_FILES):
        for j in range(random.randint(0, DEEP)):
            random_dir = DIR_NAMES[random.randint(0, len(DIR_NAMES) - 1)]
            new_dir = os.path.join(new_dir, random_dir)
            if not os.path.isdir(new_dir):
                os.mkdir(new_dir)
        file_name = ''.join([random.choice(FILE_NAMES), '.txt'])
        if random.randint(1, 2) == 1:
            file_name = file_name.lower()
        new_file = os.path.join(new_dir, file_name)
        print("create file:", new_file)
        pfile = open(new_file, 'w')
        pfile.close()
        new_dir = root


if __name__ == "__main__":
    CreateTestPolygon()
