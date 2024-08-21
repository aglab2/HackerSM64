import os

def find_and_compare_files(directory, extensions):
    # Determine the maximum length of extensions for padding
    max_ext_length = 4
    # Determine the length for zero-padding based on the maximum file size (0x800000)
    max_size_length = len(str(0x800000))

    # Walk through all directories and subdirectories
    for root, dirs, files in os.walk(directory):
        # Iterate through all files in the current directory
        for filename in files:
            if filename.endswith(extensions[0]):  # The main file (e.g., ".szp")
                # Remove the main extension to get the base filename
                base_filename = filename[:-len(extensions[0])]

                # Construct paths for the files with each extension
                file_paths = [os.path.join(root, base_filename + ext) for ext in extensions]

                # Check if all related files exist
                if all(os.path.exists(path) for path in file_paths):
                    # Get the sizes of all files
                    size_list = [(ext, os.path.getsize(path)) for ext, path in zip(extensions, file_paths)]

                    # Sort the list by file size in ascending order
                    size_list.sort(key=lambda x: x[1])

                    # Prepare the output, starting with the smallest file's size
                    formatted_sizes = [str(size_list[0][1]).ljust(max_size_length)]

                    # Calculate differences for subsequent files
                    for i in range(1, len(size_list)):
                        diff = size_list[i][1] - size_list[i - 1][1]
                        formatted_sizes.append(str(diff).ljust(max_size_length))

                    # Format the output with padded extensions and computed size differences
                    sorted_output = [
                        f"{ext[5:].ljust(max_ext_length)} ({size})"
                        for (ext, _), size in zip(size_list, formatted_sizes)
                    ]
                    print(f"{' < '.join(sorted_output)} for {file_paths[0]}")
                else:
                    print(f"Related files not found for {os.path.join(root, filename)}")

# Example usage
directory_path = "./build"
extensions = [".szp.lz4t", ".szp.lz3t", ".szp.yay0", ".szp.lz4", ".szp.lz4u", ".szp.lz3u"]  # List of extensions to check
find_and_compare_files(directory_path, extensions)
