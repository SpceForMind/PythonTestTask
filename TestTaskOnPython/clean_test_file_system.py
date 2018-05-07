
import os


matrix_files = []  
directory_ways = []


def DeleteTxtFiles(matrix_files, directory_ways):
    root_dir = os.getcwd()
    
    for i in range(len(directory_ways)): 
        for file_name in matrix_files[i]:
            cur_file = directory_ways[i] + '/' + file_name
            #delete files only from root directory
            if str(cur_file).endswith('.txt') and os.path.split(cur_file)[0] != root_dir:
                print("rm", cur_file)
                os.remove(cur_file)


def DeleteTestDirs(directory_ways):
    root_dir = os.getcwd()
    
    #start with last directory of level deep
    for i in range(len(directory_ways) - 1, -1, -1):
        if directory_ways[i]!= root_dir:
            print("rm -rf", directory_ways[i])
            os.rmdir(directory_ways[i])

def WalkForRootDirectory(directory_ways, matrix_files):
    root_dir = os.getcwd()
    for dir_w, dirs, files in os.walk(root_dir):
        directory_ways.append(dir_w)
        matrix_files.append(files)



if __name__ == "__main__":
    WalkForRootDirectory(directory_ways, matrix_files)
    DeleteTxtFiles(matrix_files, directory_ways)
    DeleteTestDirs(directory_ways)
