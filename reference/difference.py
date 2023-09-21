# File that returns difference betwene two strings
# Used to find difference in correct output and Algorithm output

def read_file_content(file_path):
    try:
        with open(file_path, 'r') as file:
            return file.read()
    except FileNotFoundError:
        print(f"File not found: {file_path}")
        return ""

def find_different_characters_indices(str1, str2):
    indices = []
    min_len = min(len(str1), len(str2))

    for i in range(min_len):
        if str1[i] != str2[i]:
            indices.append(i)

    # If one string is longer than the other, add the remaining characters to the indices.
    if len(str1) > len(str2):
        indices.extend(range(min_len, len(str1)))
    elif len(str2) > len(str1):
        indices.extend(range(min_len, len(str2)))

    return indices

# Input file paths
file_path1 = "file1.txt"
file_path2 = "file2.txt"

# Read the contents of the files
string1 = read_file_content("myOutput.txt")
string2 = read_file_content("realOutput.txt")

if string1 and string2:
    different_indices = find_different_characters_indices(string1, string2)
    
    if different_indices:
        print("Different characters found at these indices:")
        print(different_indices)
    else:
        print("The strings are identical.")