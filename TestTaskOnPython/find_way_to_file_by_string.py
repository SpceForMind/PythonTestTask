
import os

def PrintMatrix(full_ways, matrix_dirs, matrix_files):
    for i in range(len(full_ways)):
        print('full way:', full_ways[i])
        print('directores:', matrix_dirs[i])
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
            if FileName(str(cur_file)) == c:
                print(full_ways[i] + '/' + str(cur_file))
                matrix_files[i].remove(cur_file)
                return
            


def main():
    string = input()
    correct_str = CorrectString(string)

    root_directory = os.getcwd()
    full_ways = []
    matrix_dirs = []
    matrix_files = []


    for d, dirs, files in os.walk(root_directory):
        full_ways += [d]
        matrix_dirs += [dirs]
        matrix_files += [files]

   #PrintMatrix(full_ways, matrix_dirs, matrix_files)

    for c in correct_str:
        FindFilesFromStr(full_ways, matrix_files, c)

main()
