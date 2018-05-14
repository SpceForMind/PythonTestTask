
import os
import argparse


directory_ways = []
matrix_files = []


def PrintMatrix(directory_ways, matrix_files):
    for i in range(len(directory_ways)):
        print('directory way:', directory_ways[i])
        print('files:', matrix_files[i])

#delete character that is not a letter
def CorrectString(string):
    new_str = ''
    for c in string:
        if c.isalpha():
            new_str = ''.join([new_str, c])
    return new_str

def FileName(cur_file):
    return cur_file[0]

#find file with current letter in string
def FindFilesFromStr(directory_ways, matrix_files, c):
    for i in range(len(directory_ways)):
        for cur_file in matrix_files[i]:
            if FileName(cur_file) == c and cur_file.endswith('.txt'):
                print(os.path.join(directory_ways[i], cur_file))
                matrix_files[i].remove(cur_file)
                return
            
def CreateParser():
    parser = argparse.ArgumentParser()
    parser.add_argument("string", nargs = '?') #expected one word for argument
    return parser
    
def WalkForRootDirectory(directory_ways, matrix_files):
    root_directory = os.getcwd()
    for f_way, dirs, files in os.walk(root_directory):
        directory_ways.append(f_way)
        matrix_files.append(files)

#Find way to files by current alpha from string
def FindWays(directory_ways, matrix_files):
     for c in CorrectString(CreateParser().parse_args().string):
        FindFilesFromStr(directory_ways, matrix_files, c)

if __name__ == "__main__":
    WalkForRootDirectory(directory_ways, matrix_files) #initialize directory_ways and matrix_files 
    FindWays(directory_ways, matrix_files)

