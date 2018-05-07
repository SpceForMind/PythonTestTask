
import os


matrix_files = []  
matrix_dir_ways = []


def DeleteTxtFiles(matrix_files, matrix_dir_ways):
    root_dir = os.getcwd()
    
    for i in range(len(matrix_dir_ways)): 
        for file_name in matrix_files[i]:
            cur_file = matrix_dir_ways[i] + '/' + file_name
            if str(cur_file).endswith('.txt'):
                print("rm", cur_file)
                os.remove(cur_file)


def DeleteTestDirs(matrix_dir_ways):
    root_dir = os.getcwd()
    
    #start with last directory of level deep
    for i in range(len(matrix_dir_ways) - 1, -1, -1):
        if matrix_dir_ways[i]!= root_dir:
            print("rm -rf", matrix_dir_ways[i])
            os.rmdir(matrix_dir_ways[i])

def WalkForRootDirectory(matrix_dir_ways, matrix_files):
    root_dir = os.getcwd()
    for dir_w, dirs, files in os.walk(root_dir):
        matrix_dir_ways.append(dir_w)
        matrix_files.append(files)



if __name__ == "__main__":
    WalkForRootDirectory(matrix_dir_ways, matrix_files)
    DeleteTxtFiles(matrix_files, matrix_dir_ways)
    DeleteTestDirs(matrix_dir_ways)
