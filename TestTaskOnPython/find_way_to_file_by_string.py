
import os
import sys

def PrintMatrix(full_ways, matrix_files):
    for i in range(len(full_ways)):
        print('full way:', full_ways[i])
        print('files:', matrix_files[i])

#delete character that is not a letter
def CorrectString(string):
    new_str = ''
    for c in string:
        if str(c).isalpha():
            new_str += c
    return new_str

def FileName(cur_file):
    return cur_file[0]

#find file with current letter in string
def FindFilesFromStr(full_ways, matrix_files, c):
    for i in range(len(full_ways)):
        for cur_file in matrix_files[i]:
            if FileName(str(cur_file)) == c and (str(cur_file)).endswith('.txt'):
                print(full_ways[i] + '/' + str(cur_file))
                matrix_files[i].remove(cur_file)
                return
            


if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("No string for find way!")
        sys.exit(1)
    correct_str = CorrectString(sys.argv[1])

    root_directory = os.getcwd()
    full_ways = []
    matrix_files = []


    for f_way, dirs, files in os.walk(root_directory):
        full_ways.append(f_way)
        matrix_files.append(files)

    #PrintMatrix(full_ways, matrix_files)

    for c in correct_str:
        FindFilesFromStr(full_ways, matrix_files, c)
